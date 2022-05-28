class Solution {
public:
    
    int houserobb(vector<int>& nums,vector<int>&dp,int i){
        
        if(i==0){
            return dp[0]=nums[i];
        }
        if(i==1){
            return dp[1]=max(nums[0],nums[1]);
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i]=max(nums[i]+houserobb(nums,dp,i-2),houserobb(nums,dp,i-1));
        return dp[i];
    }
    
    int houseRobbBTU(vector<int> &nums,int n){
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        
        return dp[n];
        
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return houserobb(nums,dp,nums.size()-1);
        
    }
};