class Solution {
public:
     int fibTOP(int n,vector<int> &dp){
        if(n==0 or n==1){
            return n;
        }
        if(n==2){
            return 1;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=fibTOP(n-1,dp)+fibTOP(n-2,dp)+fibTOP(n-3,dp) ;
        return dp[n];
    }
    
    
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return fibTOP(n,dp);
    }
};