class Solution {
public:
    
    int minPathsumTp(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        dp[i][j]=grid[i][j]+min(minPathsumTp(i-1,j,dp,grid),minPathsumTp(i,j-1,dp,grid));
        
        return dp[i][j];
        
    }
    
    int minPathSumBU(int n,int m,vector<vector<int>>&grid){
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int up=grid[i][j]+dp[i+1][j];
                    int down=grid[i][j]+dp[i][j+1];
                    dp[i][j]=min(up,down);   
                }
            }
        }
        return dp[n][m];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return minPathsumTp(n-1,m-1,dp,grid);
    }
};