class Solution {
public:
    int minimumDeletions(string word, int k) {
        
        map<char,int>mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }

        vector<int>arr;
        for(auto i:mp) arr.push_back(i.second);
        sort(arr.begin(),arr.end());
     int ans=INT_MAX;
       for(int i=0;i<arr.size();i++){
        int start=arr[i];
        int end=arr[i]+k;
        int cnt=0;
        for(int j=0;j<i;j++){
            cnt+=arr[j];
        }
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]>end) cnt+=arr[j]-end;
        }
        ans=min(ans,cnt);
       }
       return ans;
    }
};