class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int maxprofit = 0;
        int minvalue = prices[0];
        for(int i =1;i<n;i++){
            int cost=prices[i]-minvalue;
            maxprofit= max(maxprofit,cost);
            minvalue=min(minvalue,prices[i]);
        }
        return maxprofit;
    }
};