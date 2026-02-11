class RideSharingSystem {
public:
    queue<int> riders, drivers;
    unordered_set<int> cancelled;
    unordered_set<int> waiting;

    RideSharingSystem() {}

    void addRider(int riderId) {
        riders.push(riderId);
        waiting.insert(riderId);
    }

    void addDriver(int driverId) {
        drivers.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        // remove cancelled riders lazily
        while (!riders.empty() && cancelled.count(riders.front())) {
            cancelled.erase(riders.front());
            waiting.erase(riders.front());
            riders.pop();
        }

        if (drivers.empty() || riders.empty())
            return {-1, -1};

        int d = drivers.front(); drivers.pop();
        int r = riders.front(); riders.pop();

        waiting.erase(r);

        return {d, r};
    }

    void cancelRider(int riderId) {
        // cancel ONLY if rider is currently waiting
        if (waiting.count(riderId)) {
            cancelled.insert(riderId);
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