class Solution {
public:
    int minicoinTD(int n,vector<int>& coin,int sum,vector<vector<int>> &dp){
        if(n==0){
            if(sum%coin[0]==0) return 1;
            return 0;
        }
        if(dp[n][sum]!=-1) return dp[n][sum];
        int notTake=minicoinTD(n-1,coin,sum,dp);
        int take=0;
        if(coin[n]<=sum){
            take=minicoinTD(n,coin,sum-coin[n],dp);
        }
        dp[n][sum]=notTake+take;
        return dp[n][sum];
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return minicoinTD(n-1,coins,amount,dp);
        // dp[0]=1;
        // sort(coins.begin(),coins.end());
        // for(int i=0;i<coins.size();i++)
        //     for(int j=coins[i];j<=amount;j++)
        //         dp[j]+=dp[j-coins[i]];
        // return dp[amount];
        
    }
};