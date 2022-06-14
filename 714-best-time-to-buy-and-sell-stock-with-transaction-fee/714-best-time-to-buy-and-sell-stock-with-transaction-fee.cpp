class Solution {
public:
    
    int maxProfitTD(int ind,int buy,vector<int>& price,vector<vector<int>>&dp,int fee){
        if(ind==price.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            profit=max(-price[ind]+maxProfitTD(ind+1,0,price,dp,fee)
                       ,maxProfitTD(ind+1,1,price,dp,fee));
        }else{
            profit=max(price[ind]+maxProfitTD(ind+1,1,price,dp,fee)-fee
                       ,maxProfitTD(ind+1,0,price,dp,fee));
        }
        
        return dp[ind][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return maxProfitTD(0,1,prices,dp,fee);
    }
};