class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        stack<pair<int, int>> st;

        for(int i = 0; i < n; i++) {
            int start = i;
            while(!st.empty() && st.top().second > heights[i]) {
                int index = st.top().first;
                int height = st.top().second;
                st.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            st.push({start, heights[i]});
        }

       while(!st.empty()){
            auto [index, height] = st.top();
            st.pop();
            maxArea = max(maxArea, height * (n - index));
       }

        return maxArea;
    }
};
