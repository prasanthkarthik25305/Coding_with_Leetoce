class Solution {
public:
 int get_splitcnt_of_grid(vector<pair<int,int>>intervals){
            vector<pair<int,int>>events;
            int active=0;
            for(auto i:intervals){
                events.push_back({i.first,+1});
                events.push_back({i.second,-1});
            }
            sort(events.begin(),events.end());
            int cnt=0;
            for(int i=0;i<events.size()-1;i++){
                active+=events[i].second;
                if(active==0) cnt++;
            }
    return cnt;
        }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>>xintervals,yintervals;
        for(auto i:rectangles){
            xintervals.push_back({i[0],i[2]});
            yintervals.push_back({i[1],i[3]});
        }
        if(get_splitcnt_of_grid(xintervals)>=2) return true;
        if(get_splitcnt_of_grid(yintervals)>=2) return true;
        return false;
    }
};