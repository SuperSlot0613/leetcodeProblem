class Solution {
public:
    
    int stairsJump(int n,vector<int> dp,vector<int> cost){
        if(n==0 || n==1) return cost[n]; // Base Case
        if(dp[n]!=-1) return dp[n];
        int onestep=cost[n]+stairsJump(n-1,dp,cost);
        int twostep=cost[n]+stairsJump(n-2,dp,cost);
        int mini=min(onestep,twostep);
        return dp[n]=mini;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,0);
        // return min(stairsJump(n-1,dp,cost),stairsJump(n-2,dp,cost));
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(int i=2;i<n;i++){
            int onestep=cost[i]+dp[i-1];
            int twostep=cost[i]+dp[i-2];
            dp[i]=min(onestep,twostep);
        }
         return min(dp[n-1],dp[n-2]);
    }
};