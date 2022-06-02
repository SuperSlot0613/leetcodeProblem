class Solution {
public:
    bool winnerSquareGame(int n) {
        
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            for(int val=1;;val++){
                if(val*val>i) break;
                if(dp[i-val*val]==0){
                    dp[i]=1;
                }
            }
        }
        
        return (dp[n]==1?true:false);
        
    }
};