class Solution {
public:
    
    int maxProfitTD(int ind,int buy,vector<int>& price,vector<vector<vector<int>>>&dp,int cap){
        if(cap==0) return 0;
        if(ind==price.size()){
            return 0;
        }
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-price[ind]+maxProfitTD(ind+1,0,price,dp,cap)
                       ,maxProfitTD(ind+1,1,price,dp,cap));
        }else{
            profit=max(price[ind]+maxProfitTD(ind+1,1,price,dp,cap-1)
                       ,maxProfitTD(ind+1,0,price,dp,cap));
        }
        
        return dp[ind][buy][cap]=profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return maxProfitTD(0,1,prices,dp,k);
    }
};