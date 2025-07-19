class Solution {
public:
    static const  int WMAX=4e4;
    static const int NMAX=4e5;
     int node_cnt=0;
     bool stop[WMAX];
    int trie[WMAX][27];
    void insert(const string& word) {
        int node = 0;
        for (char c : word) {
            int idx = (c == '/') ? 26 : (c - 'a');
            if (trie[node][idx] == 0) {
                trie[node][idx] = ++node_cnt;
            }
            node = trie[node][idx];

            // // Early stopping if a folder already ends here (to handle subfolders)
           // if (stop[node]) return;
        }
        stop[node] = true;
    }

        bool isSubfolder(const string& word) {
        int node = 0;
        for (int i = 0; i < word.size(); ++i) {
            int idx = (word[i] == '/') ? 26 : (word[i] - 'a');
            node = trie[node][idx];
            if (node == 0) return false;
            if (stop[node] && word[i + 1] == '/') return true; // found a parent folder
        }
        return false;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
     vector<string>ans;
      sort(folder.begin(),folder.end());
      for(auto val:folder) {
        if(!isSubfolder(val)) {
            insert(val);
            ans.push_back(val);
        }
      }
      return ans;
    }
};