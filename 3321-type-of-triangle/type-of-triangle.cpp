class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a=nums[0];
        int b=nums[1];
        int c=nums[2];
         if(a+b<=c || b+c<=a ||c+a<=b) return "none";
        if(a==b and b==c) return "equilateral";
        else if((a==b and b!=c)||(b==c and b!=a)||(c==a and c!=b)) return "isosceles";
        else if(a!=b and b!=c and c!=a){
           
            return "scalene";
        } 
        return "Hii";
    }
};