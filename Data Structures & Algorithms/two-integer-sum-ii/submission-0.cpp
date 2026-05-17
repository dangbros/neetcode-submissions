class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int left = 0;
        int right = num.size() - 1;
        vector<int> ans(2,0);
        while(left < right) {
            int sum = num[left] + num[right];
            if (sum == target){
                ans[0] = left + 1;
                ans[1] = right + 1;
                return ans;
            }
            else if (sum < target) {
                left++;
            }
            else{
                right--;
            }

        }

        return ans;
    }
};
