class Solution {
public:
    #define ll long long

    struct DSU {
        vector<int> par;

        DSU(int n) {
            par.resize(n);
            for (int i = 0; i < n; i++) par[i] = i;
        }

        int find(int x) {
            if (par[x] != x)
                par[x] = find(par[x]);
            return par[x];
        }

        void join(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (a < b) par[b] = a;
            else par[a] = b;
        }
    };

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu(26); 

        for (int i = 0; i < s1.size(); i++) {
            dsu.join(s1[i] - 'a', s2[i] - 'a');
        }

        string ans;
        for (char ch : baseStr) {
            int parent = dsu.find(ch - 'a');
            ans += (char)(parent + 'a');
        }

        return ans;
    }
};
