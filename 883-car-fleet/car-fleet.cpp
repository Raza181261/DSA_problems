class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> cars;

         for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

          sort(cars.begin(), cars.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        
        int fleets = 0;
        double maxTime = 0.0;

        for (auto &car : cars) {
            double time = car.second;
            // If current car takes more time, it's a new fleet
            if (time > maxTime) {
                fleets++;
                maxTime = time;  // Update slowest fleet time
            }
        }

        return fleets;
    }
};