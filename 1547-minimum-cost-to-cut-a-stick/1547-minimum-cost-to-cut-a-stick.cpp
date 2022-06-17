class Solution {
public:
    
    
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