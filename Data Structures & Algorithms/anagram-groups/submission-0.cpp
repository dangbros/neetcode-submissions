class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mpp; //maping charachters to list of anagrams

        for (int i = 0; i < strs.size(); i++) {
            vector<int> count(26, 0); //a...z
            string s = strs[i];
            for (int j = 0; j < s.size(); j++) {
                char c = s[j];
                count[int(c - 'a')]++;
            }
            mpp[count].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &p : mpp) {
            result.push_back(p.second);
        }
        return result;
    }
};
