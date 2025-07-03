class Solution {
public:
 string generate(string ans){
    for(int i=0;i<ans.size();i++){
        ans[i]=(ans[i]-'a'+1)%25+'a';
    }
    return ans;
 }
    char kthCharacter(int k) {
        string ans="a";
        string start="a";
        while(true){
            if(k<=ans.size()) break;
            start=generate(ans);
            ans+=start;
           // cout<<ans<<'\n';
        }
        return ans[k-1];
    }
};