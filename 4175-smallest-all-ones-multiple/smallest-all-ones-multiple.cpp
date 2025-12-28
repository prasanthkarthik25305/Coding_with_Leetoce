class Solution {
public:
  #define ll long long
    int minAllOneMultiple(int k) {
        ll n=1;
        int cnt=0;
        if(k==2 or k==5) return -1;
        bool chk=true;
        ll r=0;
        map<int,int>mp;
        while(chk){
            r=n%k;
            if(mp[r]>0) return -1;
            mp[r]++;
            if(r==0){
                chk=false;
            }
            n=r*10+1;

            //cout<<n<<' ';
            cnt++;
        }
       return cnt;
    }
};