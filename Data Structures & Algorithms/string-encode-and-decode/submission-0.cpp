class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for(string it : strs) {
            res += to_string(it.size()) + "#" + it;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;

        while(i < s.length()) {

            int j = i;

            while(s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));

            res.push_back(s.substr(j + 1, length));

            i = j + 1 + length;
        }

        return res;
    }
};