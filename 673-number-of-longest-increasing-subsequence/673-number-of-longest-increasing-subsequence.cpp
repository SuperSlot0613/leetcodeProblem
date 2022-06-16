
class Solution {
public:
    
     int lengthofLIS(vector<int> nums)
     {
         int n = nums.size();
         int dp[n];
         int count[n];
         dp[0] = 1;
         count[0]=1;
         for (int i = 1; i < n; i++)
         {
             dp[i] = 1;
             count[i]=1;
             for (int j = 0; j < i; j++)
             {

                 if (nums[i] > nums[j] and dp[i]<dp[j]+1){
                     dp[i] = 1 + dp[j];
                     count[i]=count[j];
                 }

                else if(dp[i]==dp[j]+1){
                     count[i]+=count[j];
                 }
             }
         }

        int mx=*max_element(dp, dp + n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(dp[i]==mx){
                cnt+=count[i];
            }

        }


        return cnt;
    }
    
    
    int findNumberOfLIS(vector<int>& nums) {
		    // int n=nums.size();
		    // vector<pair<int,int>> arr(n);
		    // for(int i=0;i<n;i++){
		    // arr[i].first=nums[i];
		    // arr[i].second=i;
		    // }
		    // sort(arr.begin(),arr.end(),compFunction);
		    // vector<int> tree(4*n,0);
		    // vector<int> lis(n,0);
		    // for(int i=0;i<n;i++){
		    // int val=arr[i].first;
		    // int index=arr[i].second;
		    // int res=query(tree,0,n-1,1,0,index-1);
		    // update(tree,lis,0,n-1,1,index,res+1);
		    // }
		    // int maxval=*max_element(lis.begin(),lis.end());
		    // int count=0;
		    // for(int i=0;i<lis.size();i++){
		    // if(lis[i]==maxval){
		    // count++;
		    // }
		    // }
        
        return lengthofLIS(nums);
        
    }
};