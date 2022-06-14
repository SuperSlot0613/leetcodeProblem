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
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return maxProfitTD(0,1,prices,dp);
    }
};