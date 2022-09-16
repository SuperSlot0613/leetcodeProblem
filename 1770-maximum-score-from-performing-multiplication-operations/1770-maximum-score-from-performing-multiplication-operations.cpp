class Solution {
public:
    
    int topdown(vector<int> nums,vector<int> multi,int st,int te,vector<vector<int>>&dp){
        int n=nums.size();
        if(te==multi.size()){
            return 0;
        }
        if(dp[te][st]!=-1){
            return dp[te][st];
        }
        
        int val=nums[st]*multi[te]+topdown(nums,multi,st+1,te+1,dp);
        int val1=nums[(n-1)-(te-st)]*multi[te]+topdown(nums,multi,st,te+1,dp);
        return dp[te][st]=max(val,val1);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size();
        int m=multipliers.size();
        
        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
        
        for(int i=m-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                dp[i][j]=max(multipliers[i]*nums[j]+dp[i+1][j+1],multipliers[i]*nums[n-1-(i-j)]+dp[i+1][j]);
            }
        }
        
        
        return dp[0][0];
    }
};