class Solution {
public:
    
    int coinCount(vector<int>& coins,int amount,vector<int>& dp){
        
        if(amount<0) return -1;
        if(amount==0) return 0;
        
        if(dp[amount]!=-1){
            return dp[amount];
        }
        
        long long result=INT_MAX;
        for(int i=0;i<coins.size();i++){
            long long resultmini=coinCount(coins,amount-coins[i],dp);
            if(resultmini==INT_MAX){
                continue;
            }
            result =min(result,resultmini);
        }
        return dp[amount]=result;
        
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
          int dp[amount+1];
          dp[0] = 0;
          for(int i=1 ; i<= amount;i++){
            dp[i] = INT_MAX;
          }
          for(int i=1;i<=amount;i++){
              for(int j=0;j<coins.size();j++){
                  if(coins[j] <= i){
                      int sub_res = dp[i-coins[j]];
                      if(sub_res != INT_MAX){
                          dp[i] = min(dp[i], sub_res+1);
                      }
                  }
              }
          }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        
        return dp[amount];
    }
};