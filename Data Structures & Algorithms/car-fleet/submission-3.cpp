class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int, greater<int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars[position[i]] = speed[i];
        }

        int count = 0;
        double slowestTime = 0;
        for (auto it: cars) {
            double time = (double) (target - it.first) / it.second;
            if (time > slowestTime) {
                count++;
                slowestTime = time;
            }
            
        }

        return count;
    }
};