class Solution {
public:
    
     int maxProfitTD(int ind,int buy,vector<int>& price,vector<vector<int>>&dp){
        if(ind>=price.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            profit=max(-price[ind]+maxProfitTD(ind+1,0,price,dp),maxProfitTD(ind+1,1,price,dp));
        }else{
            profit=max(price[ind]+maxProfitTD(ind+2,1,price,dp),maxProfitTD(ind+1,0,price,dp));
        }
        
        return dp[ind][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        // return maxProfitTD(0,1,prices,dp);
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                  int profit=0;
            if(buy){
                profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            }else{
                profit=max(prices[i]+dp[i+2][1],dp[i+1][0]);
            }

            dp[i][buy]=profit;
            }
        }
        
        return dp[0][1];
    }
};