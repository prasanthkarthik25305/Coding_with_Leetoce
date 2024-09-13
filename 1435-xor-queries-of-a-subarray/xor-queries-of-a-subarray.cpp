class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>prefix(arr.size()),ans;
        for(int i=0;i<arr.size();i++){
            if(i>0)
            prefix[i]=prefix[i-1]^arr[i];
            else prefix[i]=arr[i];
        }
        for(auto i:queries){
            int s=i[0],e=i[1];
        if(s==0) ans.push_back(0^prefix[e]);
        else ans.push_back(prefix[s-1]^prefix[e]);
        }
        return ans;
    }

};