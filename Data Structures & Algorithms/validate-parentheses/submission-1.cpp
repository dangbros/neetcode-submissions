class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> closeToOpen;
        closeToOpen[')'] = '(';
        closeToOpen['}'] = '{';
        closeToOpen[']'] = '[';

        for(char c : s) {
            if (closeToOpen.find(c) != closeToOpen.end())  
                if (!st.empty() && st.top() == closeToOpen[c])
                    st.pop();
                else
                    return false;
            else
                st.push(c);
        }

        if (!st.empty()) return false;
        else return true;
    }
};
