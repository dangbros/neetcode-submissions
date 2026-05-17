class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {

                char val = board[r][c];
                if(val == '.') continue;

                string row = string(1,val) + " in row " + to_string(r);
                string col = string(1,val) + " in col " + to_string(c);
                string box = string(1,val) + " in box " + to_string(r/3) + "-" + to_string(c/3);

                if(seen.count(row) || seen.count(col) || seen.count(box))
                    return false;

                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }

        return true;
    }
};