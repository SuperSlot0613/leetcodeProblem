class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        vector<int> dp(n,1);
        
        for(int i=1;i<=n-1;i++){
            for(int j=0;j<=i-1;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<dp.size();i++){
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};