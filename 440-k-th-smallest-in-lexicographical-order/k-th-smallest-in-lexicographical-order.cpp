class Solution {
public:
  int stepcnt(long num1,long num2,long &n){
    int gap=0;
    while(num1<=n){
        gap+=min(num2,n+1)-num1;
        num1*=10;
        num2*=10;
    }
    return gap;
  }
    int findKthNumber(long n, int k) {
        int startnum=1;  
        for(int i=1;i<k;){
             int steps=stepcnt(startnum,startnum+1,n);
            if(i+steps<=k){
                i+=steps;
                startnum++;
            }
            else{
                i++;
                startnum*=10;
            }
        }
     return startnum;
    }
};