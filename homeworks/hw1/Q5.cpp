class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;

        int maxPrice = 0;
        deque<int> maxPrices;
        for (int i = prices.size() - 2; i >= 0; i--)
        {
            maxPrice = max(maxPrice, prices[i + 1]);
            maxPrices.push_front(maxPrice);
        }

        for (int i = 0; i < prices.size() - 1; i++)
        {
            int profit = maxPrices[i] - prices[i];
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};