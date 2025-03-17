class Solution {
public:
    bool divideArray(vector<int>& nums) {
       bitset<501>cnt;
       for(auto i:nums){
        cnt.flip(i);
       }

       return (cnt.count()==0);
    }
};