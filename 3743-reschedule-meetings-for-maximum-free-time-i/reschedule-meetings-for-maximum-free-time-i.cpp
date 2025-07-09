class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
     vector<pair<int,int>>events;
        for(int i=0;i<startTime.size();i++){
            events.push_back({startTime[i],endTime[i]});
        }
        //maxdistance
        int st1,st,end1,end;
        vector<int>distance;
        for(int i=0;i<startTime.size();i++){
            if(i==0) distance.push_back(events[i].first);
            
            if(i>0)
            distance.push_back(events[i].first-events[i-1].second);
            if(i==startTime.size()-1) distance.push_back(eventTime-events[i].second);
        }
        for(auto i:distance) {
            cout<<i<<' ';
        }
        //from left
        int maxsum=0,sum=0;
       for(int left=0,right=0;right<distance.size();right++){
           sum+=distance[right];
           if(right>=k+1){
               sum-=distance[left];
               left++;
           }
           maxsum=max(maxsum,sum);
       }
        return maxsum;
    }
};