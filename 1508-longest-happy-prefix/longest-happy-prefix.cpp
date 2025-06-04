class Solution {
public:

#define ll long long
static ll mod_add(ll a, ll b, ll m) {
    a %= m; b %= m;
    return (a + b) % m;
}

static ll mod_sub(ll a, ll b, ll m) {
    a %= m; b %= m;
    return (a - b + m) % m;
}

static ll mod_mul(ll a, ll b, ll m) {
    a %= m; b %= m;
    return (a * b) % m;
}

static ll binpow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}

// Modular inverse for prime modulus using Fermat's Little Theorem
static ll mminvprime(ll a, ll m) {
    return binpow(a, m - 2, m);
}

struct Hashing{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 100000007};
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;
    Hashing(string a){
        primes =hashPrimes.size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length(); 
        for(int i = 0; i < hashPrimes.size(); i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for(int j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            } 
        }
        for(int i = 0; i < hashPrimes.size(); i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++){
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<ll> substringHash(int l, int r){
        vector<ll> hash(primes);
        for(int i = 0; i < primes; i++){
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};
   string longestPrefix(string s) {
    int n = s.size();
    int start = 0, end = 0;
    Hashing h(s);
    ll max_len = 0;

    for (ll len = 1; len < n; len++) {
        // Get prefix hash [0..len-1]
        auto prefixHash = h.substringHash(0, len - 1);
        // Get suffix hash [n-len..n-1]
        auto suffixHash = h.substringHash(n - len, n - 1);

        // Compare both hash vectors
        if (prefixHash == suffixHash) {
            max_len = len; // just track max_len
        }
    }

    // Return the longest border (prefix) of max_len
    return s.substr(0, max_len);
}

};