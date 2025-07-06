class FindSumPairs {
public:
    map<int,int>mp1,mp2;
    vector<int>num1,num2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
         int n=nums1.size();
         num1.resize(n);
         int m=nums2.size();
         num2.resize(m);

         num1=nums1;
         num2=nums2;
        for(auto i:num1){
            mp1[i]++;
        }
        for(auto j:num2){
            mp2[j]++;
        }
    }
    
    void add(int index, int val) {
        int oldVal = num2[index];
    mp2[oldVal]--;
    if (mp2[oldVal] == 0) {
        mp2.erase(oldVal); // optional: clean-up if needed
    }

    num2[index] += val;
    mp2[num2[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(auto i:mp1){
           int a=i.first;
           if(mp2[tot-a]>0){
            cnt+=i.second*mp2[tot-a];
           }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */