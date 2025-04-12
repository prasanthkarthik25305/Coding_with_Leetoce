long long tens[11] = {1};
long long C[11][11] = {{0}};
static array<char, 10> zero = {0};
// creating my first hashfuntion
struct myhash {
    size_t operator()(const array<char, 10>& v) const {
        constexpr static array<size_t, 10> primes = {3,  5,  7,  11, 13,
                                                     19, 23, 29, 31, 37};
        long long h = 0;
        for (int i = 0; i < 10; i++) {
            h^= primes[i] * v[i];
            h += (h << 4);
        }
        return h;
    }
};
class Solution {
public:
    int n;
    unordered_set<array<char, 10>, myhash> seen;
    // building 10powers
    void buildTens() {
        for (int i = 1; i <= 10; i++) {
            tens[i] = tens[i - 1] * 10;
        }
    }
    // buiding ncr in pascal technique
    void Pascal() {
        if (C[0][0] == 1)
            return;
        C[0][0] = 1;
        for (int i = 1; i <= 10; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j <= i / 2; j++) {
                C[i][j] = C[i][i - j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    // building the PalindromePermutaion
    // here firshalfpalindrome=x;
    array<char, 10> Palindrome(int x, int dz, int k) {
        // check for odd
        int sz = dz - (n & 1);
        array<char, 10> freq = {0};
        long long ans = tens[sz] * x;
        if (n & 1) {
            int r = x % 10;
            freq[r]++;
            x /= 10;
        }
        for (int i = 0; i < sz; i++) {
            char r = x % 10;
            freq[r] += 2;
            ans += r * tens[sz - 1 - i];
            x /= 10;
        }
        if (ans % k != 0)
            return zero;
        return freq;
    }

    long long Permutation(const array<char, 10>& freq) {
        int d = reduce(freq.begin(), freq.end(), 0);

        long long ans = 1;
        if (freq[0] > 0) {
            ans = C[d - 1][freq[0]];
            d -= freq[0];
        }

        for (int i = 1; i <= 9; ++i) {
            if (freq[i] > 0) {
                ans *= C[d][freq[i]];
                d -= freq[i];
            }
        }
        return ans;
    }

    long long countGoodIntegers(int n, int k) {
        this->n = n;
        if (n <= 2)
            return 9 / k;

        buildTens();
        Pascal();
        int answer = 0;
        int h = (n + 1) / 2;
        for (int i = tens[h - 1]; i < tens[h]; i++) {
            auto freq = Palindrome(i, h, k);
            if (freq != zero and !seen.count(freq)) {
                answer += Permutation(freq);
                seen.insert(freq);
            }
        }
        return answer;
    }
};