class Solution {
public:
    #define ll long long
    bool predicate(ll mid,vector<int>&ranks,ll cars){
       ll cnt=0;
       for(int i=0;i<ranks.size();i++){
        cnt+=sqrt(mid*1.0/ranks[i]);
       } 
       return cnt>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
     int n=ranks.size();
     ll low=0,mid,high=*max_element(ranks.begin(),ranks.end())*1ll*cars*cars,ans=high;
     while(low<=high){
        mid=(low+high)/2;
        if(predicate(mid,ranks,cars)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
     }   
     return ans;
    }
};