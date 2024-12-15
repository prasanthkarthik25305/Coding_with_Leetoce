#include <vector>
using namespace std;
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                
                int targetIndex = (i + nums[i]) % n;
                result[i] = nums[targetIndex];
            } else if (nums[i] < 0) {
                int targetIndex = (n+i - abs(nums[i])%n) % n; 
                result[i] = nums[targetIndex];
            } else {
                result[i] = nums[i];
            }
        }
        
        return result;
    }
};
