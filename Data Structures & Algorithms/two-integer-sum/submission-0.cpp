class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> ans(2, 0);
        if (n <= 0) return ans;

        map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            auto it = mpp.find(diff);
            if (it != mpp.end()){
                ans[0] = it->second;
                ans[1] = i;
                break;
            }
            mpp.insert({nums[i], i});
        }
        
        return ans;
    }
};
