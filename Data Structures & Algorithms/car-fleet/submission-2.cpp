class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int, greater<int>> cars;
        stack<double> st;
        for (int i = 0; i < position.size(); i++) {
            cars[position[i]] = speed[i];
        }

        for (auto it: cars) {
            double time = (double) (target - it.first) / it.second;
            if (!st.empty() && time <= st.top())
                continue;
            else
                st.push(time);
        }

        return st.size();
    }
};
