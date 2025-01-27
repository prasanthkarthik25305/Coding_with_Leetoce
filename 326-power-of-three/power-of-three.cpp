class Solution {
public:
 int rec(int n){
    if(n==1) return true;
    else if(n%3!=0) return false;
    else return rec(n/3);
 }
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        bool flag =false;
        if(n<0) flag=true;
        if(flag) return -1*rec(n);
        return rec(n);
    }
};