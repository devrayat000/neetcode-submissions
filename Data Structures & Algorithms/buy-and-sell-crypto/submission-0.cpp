class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = 0;
        for (int i = i; i < prices.size(); i++) {
            profit = max(prices[i] - buy, profit);
            buy = min(prices[i], buy);
        }
        return profit < 0 ? 0 : profit;
    }
};
