class Solution {
public:
  void generatelexy(int curr,int limit,vector<int>&ans){
    // if curr is less than limit
    if(ans.size()>=limit) return;
    if(curr>limit) return;
    ans.push_back(curr);
    for(int i=0;i<=9;i++){
        int next=curr*10+i;
        generatelexy(next,limit,ans);
    }

  }
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        for(int start=1;start<=n;start++){
          generatelexy(start,n,res);
        }
        return res;
    }
};