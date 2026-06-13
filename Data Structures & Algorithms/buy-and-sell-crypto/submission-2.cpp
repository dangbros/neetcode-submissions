class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0;

        for(auto price: prices) {
            // calculates the min of the current iteration and the minPrice
            minPrice = min(minPrice, price);

            // calculates the profit with the current interation and the minPrice
            int profit = price - minPrice;

            //if the current profit is greater than the maxprofit, replace the prev maxProfit
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;

    }
};
