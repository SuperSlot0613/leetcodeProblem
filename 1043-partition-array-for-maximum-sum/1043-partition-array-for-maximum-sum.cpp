class Solution {
public:
    
    int maxsumTD(int ind,vector<int>&nums,vector<int>&dp,int k){
        if(ind==nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int len=0;
        int maxi=INT_MIN;
        int maxans=INT_MIN;
        
        for(int j=ind;j<(ind+k<nums.size()?ind+k:nums.size());j++){
            len++;
            maxi=max(maxi,nums[j]);
            int sum=len*maxi+maxsumTD(j+1,nums,dp,k);
            maxans=max(maxans,sum);
        }
        dp[ind]=maxans;
        return dp[ind];
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return maxsumTD(0,arr,dp,k);
    }
};