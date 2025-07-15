class Solution {
public:

    bool contain_num_alph(string s){
        bool chk1,chk2;
        for(int i=0;i<s.size();i++){
            if(s[i]-'0'>=0 and s[i]-'0'<=9) chk1=true;
            else if((s[i]>='a' and s[i]<='z') || (s[i]>='A' and s[i]<='Z')) chk2=true;
            else return false;
        }
        if(chk1 and chk2) return true;
        else return false;
    }
    bool atleastv_c(string s) {
        bool chk1=false,chk2=false;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='a'||s[i]=='e' ||s[i]=='i' ||s[i]=='o'||s[i]=='u' ||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O' ||s[i]=='U') chk1=true;
            else if((s[i]>='a' and s[i]<='z')||(s[i]>'A' and s[i]<='Z')) chk2=true;
        }
        if(chk1 and chk2) return true;
        else return false;
    }
    bool isValid(string s) {
     if(s.size()>=3){
        if(contain_num_alph(s)){
            if(atleastv_c(s)){
                return true;
            }
        }
     }
        return false;
    }
};