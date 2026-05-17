class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mpp; //maping charachters to list of anagrams

        for (int i = 0; i < strs.size(); i++) {
            vector<int> count(26, 0); //a...z
            string s = strs[i]; // collect each string into a var
            for (int j = 0; j < s.size(); j++) { // loop through the string to get the freq
                char c = s[j]; // collect the char
                count[int(c - 'a')]++; // increment the char size index
            }
            mpp[count].push_back(s); // push that array as key of the map and also push the string as the value
        }

        vector<vector<string>> result; //create a resultant array
        for (auto &p : mpp) { //iterate through the map 
            result.push_back(p.second); // put the string vector inside the resultant vector
        }
        return result; // return the vector as final answer
    }
};
