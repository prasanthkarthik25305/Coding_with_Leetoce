class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        colors.insert(colors.end(),colors.begin(),colors.begin()+(k-1));
        int n=colors.size();
        int cnt=0;
        for(int left=0,right=0;right<n;right++){
            if(right>0 and colors[right]==colors[right-1]){
                left=right;
            }
            if(right-left+1>=k) cnt++;
        }
        return cnt;
    }
};