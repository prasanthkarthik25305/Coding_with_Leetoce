class Solution {
public:
  #define ll long long
    int minAllOneMultiple(int k) {
        ll n=1;
        int cnt=0;
        if(k==2 or k==5) return -1;
        bool chk=true;
        ll r=1%k;
        map<int,int>mp;
        while(chk){
            if(r==0) chk=false;
            r=(r*10+1)%k;
            if(mp[r]>0) return -1;
            mp[r]++;
            //cout<<n<<' ';
            cnt++;
        }
       return cnt;
    }
};