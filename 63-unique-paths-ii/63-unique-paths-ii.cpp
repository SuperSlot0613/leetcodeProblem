class Solution {
public:
    
    int totalpath=0;
    
    bool IsSafe(int i,int j,int row,int col,vector<vector<int>>& visited)
	{
		return (i>=0 && j>=0&&i<row&&j<col&&visited[i][j]==0);
	}
    
    void helper(int i,int j,int row,int col,vector<vector<int>>& visited,vector<vector<int>>& grid){
        if(i==row-1 && j==col-1 && grid[i][j]==0)
		{
			totalpath++;
			return;
		}
        
        if(!IsSafe(i,j,row,col,visited)){
            return;
        }
        visited[i][j]=1;
        if(i+1<row && grid[i][j]==0)//down move
			helper(i+1,j,row,col,visited,grid);
		if(j+1<col && grid[i][j]==0 )//right  move
			helper(i,j+1,row,col,visited,grid);
        visited[i][j]=0;
        return;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // int row=grid.size();
        // int col=grid[0].size();
        // vector<vector<int>> visited(row,vector<int>(col,0));
        // helper(0,0,row,col,visited,grid);
        // return totalpath;
      int n=grid.size(),m=grid[0].size();
      int dp[n][m];
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          if(grid[i][j]==1) dp[i][j]=0;
          else if(i==0 && j==0) dp[i][j]=1;
          else {
            int left=0,up=0;
            if(i>0) up=dp[i-1][j];
            if(j>0) left=dp[i][j-1];
            dp[i][j]=left+up;
          }
        }
      }
      return dp[n-1][m-1];
    }
};