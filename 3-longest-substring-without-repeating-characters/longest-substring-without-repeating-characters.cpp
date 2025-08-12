class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int left=0,len=0;
    map<char,int>mp;
     for(int right=0;right<s.size();right++){

        while(mp.find(s[right])!=mp.end() and left<right){
            mp[s[left]]--;
            if(mp[s[left]]==0) mp.erase(s[left]);
            left++;
           // cout<<s[right]<<right<<'\n';
        }
        mp[s[right]]++;
        len=max(len,right-left+1);
     }
     return len;
    }
};