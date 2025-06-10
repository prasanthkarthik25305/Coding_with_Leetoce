class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        int min=INT_MAX,maxy=INT_MIN;
        for(auto i:mp){
            if(i.second%2==0){
                if(min>i.second){
                    min=i.second;
                }
            }
            else{
                if(maxy<i.second)maxy=i.second;
            }
        }
        return maxy-min;
    }
};