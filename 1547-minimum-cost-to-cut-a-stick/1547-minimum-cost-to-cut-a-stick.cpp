class Solution {
public:
    
    int unboundknapsackBU(int N,std::vector<int> val){
        int n=val.size();
        vector<int> prev(N+1,0),curr(N+1,0);
        for(int i=0;i<=N;i++){
            prev[i]=(N)*val[i];
        }

        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=N;t++){
                int notTake=prev[t];
                int take=INT_MIN;
                int rodlength=ind+1;
                if(rodlength<=t){
                    take=val[ind]+curr[t-rodlength];
                }
                curr[t]=min(notTake,take);
            }
            prev=curr;
        }
        return prev[N];

    }
    
    int rodcutting(int ind,int N,vector<int> val,vector<vector<int>>& dp){
        if(ind==0){
            return (N)*val[0];
        }
        if(dp[ind][N]!=-1) return dp[ind][N];
        int notTake=rodcutting(ind-1,N,val,dp);
        int take=INT_MAX;
        int rodlength=ind+1;
        if(rodlength<=N){
            take=val[ind]+rodcutting(ind,N-rodlength,val,dp);
        }
        dp[ind][N]=min(notTake,take);
        return dp[ind][N];
    }
    
     int f(int n, int c,vector<int>& cuts,int i,int j, vector<vector< int>>&dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int mini=1e7;
        
    
        for(int ind=i;ind<=j;ind++)
        {
            int steps=cuts[j+1]-cuts[i-1]+f(n,c,cuts,i,ind-1,dp)+f(n,c,cuts,ind+1,j,dp);
            mini=min((int)steps,mini);
        }
        return dp[i][j]=mini;
            
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        
        sort(cuts.begin(),cuts.end());
        vector<vector< int>>dp(c+1,vector<int>(c+1,-1));
        return f(n,c,cuts,1,c,dp);
      
    }
};