class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0) return false;
        map<int, int> mpp;
        for(int i = 0; i < n; i++) {
            if(mpp.find(nums[i]) != mpp.end()) {
                return true;
            }
            mpp.insert({nums[i], 1});
        }
        return false;
    }
};