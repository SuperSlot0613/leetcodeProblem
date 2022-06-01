class Solution {
public:
    int count=0;
    int minicoinTD(vector<int>& coin,int sum,vector<int> &dp){
        if(sum==0){
            count++;
            return 0;
        }
        if(dp[sum]!=-1) return dp[sum];
        long long result=INT_MAX;
        for(int i=0;i<coin.size();i++){
            long long resultmini=minicoinTD(coin,sum-coin[i],dp);
            if(resultmini==INT_MAX)
                continue;
            result=min(result,1+resultmini);
        }
        return dp[sum]=result;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;
        sort(coins.begin(),coins.end());
        for(int i=0;i<coins.size();i++)
            for(int j=coins[i];j<=amount;j++)
                dp[j]+=dp[j-coins[i]];
        return dp[amount];
        
    }
};