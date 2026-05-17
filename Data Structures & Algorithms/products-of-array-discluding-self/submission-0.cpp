class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> outputs(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (i == j) continue;
                else outputs[i] *= nums[j];
            }
        }
        return outputs;
    }
};
