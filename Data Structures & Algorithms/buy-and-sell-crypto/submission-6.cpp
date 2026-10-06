class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r = 0;
        int i = 0;
        int max_profit = 0;
        while(i<prices.size()){
            if(prices[i] > prices[r]) {
                r = i;
                max_profit = max(max_profit,prices[r]-prices[l]);
                ++i;
                continue;
            }
            if(prices[i] < prices[l]) l=i,r = i;
            ++i;
        } 
        return max_profit;
    }
};
