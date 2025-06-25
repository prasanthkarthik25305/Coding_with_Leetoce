class Solution {
public:
    int f(vector<int>& nums2, long long x1, long long v) {
       // cout<<"In this function: \n";
        int n2 = nums2.size();
        int left = 0, right = n2 - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
          ////  cout<<"mid2: "<<mid<<' ';
            if (x1 >= 0 && nums2[mid] * x1 <= v ||
                x1 < 0 && nums2[mid] * x1 > v) {
                left = mid + 1;
               // cout<<"THen lef2t: "<<left<<' ';
            } else {
                right = mid - 1;
                //cout<<"Then right2: "<<right<<' ';
            }
           // cout<<'\n';
        }
        if (x1 >= 0) {
            //cout<<"left: "<<left<<'\n';
            return left;
        } else {
           // cout<<"right: "<<n2-left<<'\n';
            return n2 - left;
        }
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        int n1 = nums1.size();
        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = (left + right) / 2;
           // cout<<"mid1: "<<mid<<' ';
            long long count = 0;
            for (int i = 0; i < n1; i++) {
                //cout<<"nums[i]: "<<nums1[i]<<'\n';
                count += f(nums2, nums1[i], mid);
                //cout<<"Cnt: "<<count<<' ';
            }
            if (count < k) {
                left = mid + 1;
                //cout<<"left1: "<<left<<' '<<right<<' ';
            } else {

                right = mid - 1;
                //cout<<"right :"<<right<<' '<<left<<' ';
            }
            //cout<<'\n';
        }
        return left;
    }
};