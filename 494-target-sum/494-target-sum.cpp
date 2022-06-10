class Solution {
public:
    
    int coutPatition(int n,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(n==0){
            if(sum==0 && arr[0]==0) return 2;
            if(sum==0 || sum==arr[0]) return 1;
            return 0;
        }
        if(dp[n][sum]!=-1) return dp[n][sum];
        int nottake=coutPatition(n-1,sum,arr,dp);
        int take=0;
        if(arr[n]>=sum){
            take=coutPatition(n-1,sum-arr[n],arr,dp);
        }
        return dp[n][sum]=(nottake+take);
   }
    
    int BottomUP(vector<int>&num,int tar){
        int n=num.size();
        vector<int> prev(tar+1,0),cur(tar+1,0);
        if(num[0]==0) prev[0]=2;
        else prev[0]=1;
        if(num[0]!=0 && num[0]<=tar) prev[num[0]]=1;
        
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=tar;sum++){
                int notTake=prev[sum];
                int take=0;
                if(num[ind]<=sum){
                    take=prev[sum-num[ind]];
                }
                cur[sum]=(notTake+take);
            }
            prev=cur;
        }
        return prev[tar];
    }

    
    int findTargetSumWays(vector<int>& arr, int d) {
        int total=accumulate(arr.begin(),arr.end(),0);
        int n=arr.size();
        if(total-d <0 || (total-d)%2) return 0;
        vector<vector<int>> dp(n,vector<int>(total+1,-1));
        return BottomUP(arr,(total-d)/2);
    }
};