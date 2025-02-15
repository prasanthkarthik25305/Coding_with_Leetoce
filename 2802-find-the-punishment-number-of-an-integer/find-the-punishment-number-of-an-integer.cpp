class Solution {
public:
     bool punishment(string chkstr,int i,int sum,int target){
        if(sum>target) return false;
        if(i==chkstr.size()) {
            if(sum==target) return true;
            return false;
        }
bool chk=false;
        for(int j=i;j<chkstr.size();j++){
            string subchk=chkstr.substr(i,j-i+1);
            int added=stoi(subchk);
            chk=chk||punishment(chkstr,j+1,sum+added,target);
            if(chk==true) return true;
        }
        return false;
     }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            string ans=to_string(i*i);
            sum+=(punishment(ans,0,0,i))?i*i:0;
        }
        return sum;
    }
};