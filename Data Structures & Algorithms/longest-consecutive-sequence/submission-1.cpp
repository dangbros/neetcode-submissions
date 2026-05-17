class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (int n: nums) {
            if (!numSet.count(n - 1)){
                int length = 1;
                while(numSet.count(n+length)){
                    length++;
                }
                longest = max(length, longest);
            }
        }

        return longest;
    }
};
