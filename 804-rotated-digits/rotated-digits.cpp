class Solution {
public:
  bool chk_digit(int n){
     int temp=n,rem=0,res=0;
     bool chk=false;
     while( n!=0){
        rem=n%10;
        if(rem == 2|| rem==5) chk=true;
        else if(rem==6 || rem==9) chk=true;
        else if(rem ==1 ||rem==0 ||rem==8) res=res;
        else return 0;
        n=n/10;
     }
     if(!chk) return 0; 
     return 1;
  }

    int rotatedDigits(int n) {
        int res=0;
        for(int i=1;i<=n;i++){
           res+=chk_digit(i);
           if(chk_digit(i)==1){
            cout<<1<<" "<<i<<'\n';
           }

        }
        return res;
    }
};

