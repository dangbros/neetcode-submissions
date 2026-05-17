class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<pair<int, int>> st;
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            while(!st.empty() && temp[i] > st.top().first) {
                int idx = st.top().second;
                st.pop();
                result[idx] = i - idx;
            }
            st.push({temp[i], i});
        }

        return result;
    }
};
