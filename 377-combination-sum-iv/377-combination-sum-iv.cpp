class Solution {
public:
   int solve(vector<int> &nums,int &n, int tar,vector<int> &dp){
        if(tar == 0) return 1;
        if(dp[tar]!=-1) return dp[tar];
        int count=0;
        for(int i=0;i<n;i++) if(nums[i]<=tar) count += solve(nums, n, tar-nums[i],dp);
        return dp[tar] = count;
    }
    int combinationSum4(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<int> dp(tar+1,-1);
        return solve(nums,n,tar,dp);;
    }
};