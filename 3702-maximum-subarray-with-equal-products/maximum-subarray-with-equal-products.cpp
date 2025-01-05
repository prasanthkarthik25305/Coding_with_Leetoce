class Solution {
public:
int mod=1e9+7;
//#define int long long
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }


    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
 //#undef int
    int maxLength(vector<int>& nums) {
        #define int long long
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int prod = 1, Gcd = 0, Lcm = 1;

            for (int j = i; j < n; ++j) {
               
                prod =prod%mod*nums[j]%mod;
                // if(prod>=1e9) break;
                Gcd = (Gcd == 0) ? nums[j] : gcd(Gcd, nums[j]);
                Lcm = lcm(Lcm, nums[j]);

                if (prod == Gcd%mod * Lcm%mod) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
        #undef int
    }
};
