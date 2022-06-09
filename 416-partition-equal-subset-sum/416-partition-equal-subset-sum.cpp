class Solution {
public:
    
    
    bool canPatitionsum(int index,int target, vector<int>&arr,vector<vector<int>>& dp){
        if(target==0) return true;
        
        if(index==0){
            return (arr[index]==target);
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        
        bool notake=canPatitionsum(index-1,target,arr,dp);
        bool take=false;
        if(target>=arr[index]){
            take=canPatitionsum(index-1,target-arr[index],arr,dp);
        }
        
        dp[index][target]=(take or notake);
        
        return dp[index][target];
        
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0){
            return false;
        }
        
        int sum=total/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return canPatitionsum(n-1,sum,nums,dp);
        
    }
};