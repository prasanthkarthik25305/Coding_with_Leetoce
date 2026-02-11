class RideSharingSystem {
public:
   queue<int>riders;
   queue<int>drivers;
    unordered_set<int> cancel;
    unordered_set<int>waiting;
    RideSharingSystem() {}
    void addRider(int riderId) {
        riders.push(riderId);
        waiting.insert(riderId);
    }
    
    void addDriver(int driverId) {

        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!riders.empty() and cancel.count(riders.front())){
            cancel.erase(riders.front());
            riders.pop();
        }
       
        if(drivers.empty() || riders.empty()) return {-1,-1};

        int d=drivers.front();
        int r=riders.front();
        waiting.erase(r);
        drivers.pop();
        riders.pop();
        return {d,r};
    }
    
    void cancelRider(int riderId) {
        if(waiting.count(riderId)){
      cancel.insert(riderId);
        }
      
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */