class Solution {
public:
    
    int maxcoinsTD(int i,int j,vector<vector<int>>& dp,vector<int>& arr){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int cost=arr[i-1]*arr[ind]*arr[j+1]+maxcoinsTD(i,ind-1,dp,arr)+maxcoinsTD(ind+1,j,dp,arr);
            maxi=max(maxi,cost);
        }
        
        return dp[i][j]=maxi;
        
    }
    
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return maxcoinsTD(1,n,dp,nums);
    }
};