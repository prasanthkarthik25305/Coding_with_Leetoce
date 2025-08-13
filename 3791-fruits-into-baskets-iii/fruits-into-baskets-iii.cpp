class Solution {
public:
    const int NEG_INF = -1e9;
    vector<int> tree;
    int n;

    void Build(vector<int> arr) {
        n = 1;
        int size = arr.size();
        while (n < size) {
            n *= 2;
        }

        tree.assign(2 * n, NEG_INF);

        copy(arr.begin(), arr.end(), tree.begin() + n);

        for (int i = n - 1; i >= 0; i--) {
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int Find_leftmost(int x) {
        if (tree[1] < x)
            return -1;
        // start from top
        int ind = 1;
        while (ind < n) {
            if (tree[2 * ind] >= x) {
                ind = 2 * ind;
            } else {
                ind = 2 * ind + 1;
            }
        }
        return ind - n;
    }

    void update(int pos, int new_val) {
        pos += n;
        tree[pos] = new_val;
        pos /= 2;
        while (pos >= 1) {
            tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
            pos /= 2;
        }
    }

    int numOfUnplacedFruits(vector<int> & fruits, vector<int> & baskets) {

       Build(baskets);
       int cnt=0;
       for(auto f:fruits){
        int ind=Find_leftmost(f);
        if(ind!=-1){
            update(ind,NEG_INF);
        }
        else{
            cnt++;
        }
       }
       return cnt;
    }
};