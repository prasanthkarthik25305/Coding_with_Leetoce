class Solution {
public:
    int maxVowels(string s, int k) {
     int cnt=0,maxy=INT_MIN;
     for(int i=0;i<k;i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            cnt++;
        }
     }   
     maxy=max(maxy,cnt);
     for(int i=k;i<s.size();i++){
        if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u'){
            cnt--;
        }
         if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            cnt++;
        }
        maxy=max(maxy,cnt);

     }
     return maxy;
    }
};