class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int cnt1=0,ans=n;
        for(int left=0,right=0;right<n;right++){
         if(blocks[right]=='W') cnt1++;
         if(right-left+1==k){
            ans=min(ans,cnt1);
            cnt1-=(blocks[left]=='W')?1:0;
            left++;
         }
        }
        return ans;
    }
};