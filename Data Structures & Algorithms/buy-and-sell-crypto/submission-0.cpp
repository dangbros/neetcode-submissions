class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() - 1;
        int minPrice = INT_MAX, maxProfit = INT_MIN;

        for(auto price: prices) {
            minPrice = min(minPrice, price);
            int profit = price - minPrice;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;

    }
};
