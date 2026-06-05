class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int rows = arr.size();
        int cols = arr[0].size();

        int top = 0;
        int bot = rows - 1;

        while (top <= bot) {
            int row = (top + bot) / 2;
            if (target > arr[row][cols - 1])
                top = row + 1;
            else if (target < arr[row][0])
                bot = row - 1;
            else
                break;
        }

        if (!(top <= bot))
            return 0;
        
        int row = (top + bot) / 2;
        int l = 0;
        int r = cols - 1;
        
        while(l <= r){
            int mid = (l + r) / 2;
            if (target > arr[row][mid])
                l = mid + 1;
            else if (target < arr[row][mid])
                r = mid - 1;
            else
                return 1;
        }

        return 0;
    }
};
