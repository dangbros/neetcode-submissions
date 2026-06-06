class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;
        int ans;
        while(low <= high) {
            int k = (low + high) / 2;
            int time = 0;
            for(auto pile: piles) {
                time += ceil((double) pile / k);
            }

            if (time <= h){
                ans = k;
                high = k - 1;
            }
            else {
                low = k + 1;
            }
        }

        return ans;
    }
};
