class Solution {
public:
    
    int lengthofLisTd(int ind,int prev,vector<int>& arr,vector<vector<int>>& dp){
        if(ind==arr.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int len=lengthofLisTd(ind+1,prev,arr,dp);
        int len1=0;
        if(prev==-1 || arr[ind]>arr[prev]){
            len1=1+lengthofLisTd(ind+1,ind,arr,dp);
        }
        return dp[ind][prev+1]=max(len,len1);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return lengthofLisTd(0,-1,nums,dp);
//         vector<int> dp(n,1);
        
//         for(int i=1;i<=n-1;i++){
//             for(int j=0;j<=i-1;j++){
//                 if(nums[i]>nums[j]){
//                     dp[i]=max(dp[i],1+dp[j]);
//                 }
//             }
//         }
        
//         int ans=INT_MIN;
        
//         for(int i=0;i<dp.size();i++){
//             ans=max(ans,dp[i]);
//         }
        
//         return ans;
    }
};