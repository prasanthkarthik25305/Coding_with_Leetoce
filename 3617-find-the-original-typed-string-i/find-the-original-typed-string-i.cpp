class Solution {
public:
    int possibleStringCount(string word) {
        int maxy=0,cnt=0,chk=INT_MAX;
         for(int i=0;i<word.size();i++){
            if(word[i]==word[i+1]){
                chk=min(chk,i);
            }
            else if(chk!=INT_MAX) {
                maxy+=(i-chk);
                chk=INT_MAX;
               // cnt=0;
            }
            }
            return maxy+1;
         }
};