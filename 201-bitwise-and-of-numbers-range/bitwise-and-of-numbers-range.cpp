class Solution {
public:
    long long setBitNumber(int n)
{
  //this will be the answer going to return
  //This will work for 64-bit if using with long long
  //while in-built functions overflow 
    long long ans = 1;
    while (n) {
        ans *= 2;
        n /= 2;
    }
      ans/=2;
    return ans;
}
    int rangeBitwiseAnd(int left, int right) {
        if(abs(left-right)<2) return left&right;
        if(abs(left-right)>33){
            if(setBitNumber(left)==setBitNumber(right)) return setBitNumber(left);
            else return 0;
        }
        else {
            long long ans=left;
            for(long long i=left+1;i<=right;i++){
             ans=ans&i;
            }
            return ans;
        }
    }
};