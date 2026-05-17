class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c){return !isalnum(c);}), s.end());

        for(auto& c : s){
            c = tolower(c);
        }
        int n = s.size();
        int begin = 0;
        int end = n - 1;

        while(begin <= end){
            if(s[begin] != s[end])
                return false;
            begin++;
            end--;
        }

      

        return true;
    }
};
