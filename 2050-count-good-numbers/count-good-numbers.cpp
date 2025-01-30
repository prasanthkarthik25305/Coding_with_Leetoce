class Solution {
public:
int mod=1e9+7;
 #define int long long
int binpow(int a,int b){
   
    if(b==0) return 1;
    int ans=binpow(a,b/2);
    if(b%2==0) return ((ans)%mod*(ans)%mod)%mod;
    else return ((((ans)%mod*(ans)%mod)%mod)*a%mod)%mod;
}
    int countGoodNumbers(long long n) {
        int sum=0;
       int e1=ceil(n*1.0/2);
       int e2=n/2;
       sum=(binpow(5,e1)*binpow(4,e2))%mod;
       return sum;
       #undef int
    }
};