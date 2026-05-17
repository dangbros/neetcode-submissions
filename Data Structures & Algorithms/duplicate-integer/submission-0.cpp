class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size() <= 0) return false;
        map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++) {
            if(mpp.find(nums[i]) != mpp.end()) {
                return true;
            }
            mpp.insert({nums[i], 1});
        }
        return false;
    }
};