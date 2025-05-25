class Solution {
public:
    bool isprime(long long n) {
        if (n < 2) return false;
        for (long long i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        unordered_set<long long> primes;
        
        for (int i = 0; i < s.size(); ++i) {
            long long num = 0;
            for (int j = i; j < s.size(); ++j) {  
                num = num * 10 + (s[j] - '0');
                if (isprime(num)) {
                    primes.insert(num); 
                }
            }
        }

        vector<long long> primeList(primes.begin(), primes.end());
        sort(primeList.rbegin(), primeList.rend());

        long long sum = 0;
        for (int i = 0; i < min(3, (int)primeList.size()); ++i) {
            sum += primeList[i];
        }

        return sum;
    }
};
