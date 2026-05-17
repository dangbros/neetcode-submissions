class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;

        for(int n : nums)
            freq[n]++;

        int n = nums.size();

        vector<vector<int>> bucket(n + 1);

        for(auto it : freq){
            int num = it.first;
            int count = it.second;
            bucket[count].push_back(num);
        }

        vector<int> result;

        for(int i = n; i >= 0 && result.size() < k; i--){
            for(int n : bucket[i]){
                result.push_back(n);
                if (result.size() == k) 
                    return result;
            }
        }

        return result;
    }
};
