class Solution {
public:
    
    int robhouseBu(int n,vector<int> &arr){
        vector<int> dp(n,0);
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        return dp[n-1];
   }
    
    int rob(vector<int>& nums) {
        
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        vector<int>v1,v2;
        if(nums.size()==1)return nums[0];
        for(int i=0;i<nums.size()-1;i++)v1.push_back(nums[i]);
        for(int i=1;i<nums.size();i++)v2.push_back(nums[i]);
        return max(robhouseBu(v1.size(),v1),robhouseBu(v2.size(),v2));
    }
};