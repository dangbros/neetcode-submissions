class Solution {
public:

    bool linearSearch(vector<int>& nums, int target) {
        for(int num : nums) {
            if (num == target) {
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;

        for (int num : nums) {
            int currentNum = num;
            int count = 1;

            while(linearSearch(nums, currentNum + 1)) {
                currentNum++;
                count++;
            }

            longest = max(longest, count);
        }

        return longest;
    }
};
