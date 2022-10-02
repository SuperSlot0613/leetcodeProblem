class Solution {
public:
    int dp[31][1001];
    int mod = 1e9 + 7;
    int solve(int chances , int k , int rem )
    {
        if(chances==0 && rem==0) return 1;
        if(chances==0 || rem<=0) return 0;
        
        if(dp[chances][rem]!=-1) return dp[chances][rem];
        int ans = 0;
        for(int i = 1; i<=k ; i++)
            ans = (ans%mod + solve(chances-1 , k , rem-i)%mod)%mod;

        return dp[chances][rem] = ans;
 
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target);
    }
};