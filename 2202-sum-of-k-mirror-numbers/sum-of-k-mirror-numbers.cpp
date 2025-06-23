class Solution {
public:
    typedef long long ll;

    bool isPalindrome(const string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    string toBaseK(ll n, int k) {
        string res;
        while (n > 0) {
            res += (n % k) + '0';
            n /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<ll> findKMirror(int k, int n) {
        vector<ll> result;
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        // Generate odd and even decimal palindromes separately and push to min-heap
        for (int len = 1; result.size() < n; len++) {
            int start = (len == 1) ? 1 : pow(10, len - 1);
            int end = pow(10, len);

            for (int half = start; half < end; ++half) {
                string s = to_string(half);
                string rev = s;
                reverse(rev.begin(), rev.end());

                // Odd-length palindrome
                string oddStr = s + rev.substr(1);
                ll odd = stoll(oddStr);
                pq.push(odd);

                // Even-length palindrome
                string evenStr = s + rev;
                ll even = stoll(evenStr);
                pq.push(even);
            }

            // Now extract from min-heap
            while (!pq.empty() && result.size() < n) {
                ll num = pq.top(); pq.pop();
                string baseStr = toBaseK(num, k);
                if (isPalindrome(baseStr)) {
                    result.push_back(num);
                }
            }
        }

        return result;
    }

    long long kMirror(int k, int n) {
        vector<ll> res = findKMirror(k, n);
        long long sum = 0;
        for (ll x : res) sum += x;
        return sum;
    }
};
