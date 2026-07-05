class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        for(int i = 0; i < s2.size(); i++) {
            string window = s2.substr(i, s1.size());
            sort(window.begin(), window.end());
            if (s1 == window)
                return true;
        }
        return false;
    }
};
