class Solution {
public:
    int totalpath=0;
    
    bool IsSafe(int i,int j,int row,int col,vector<vector<int>>& visited)
	{
		return (i>=0 && j>=0&&i<row&&j<col&&visited[i][j]==0);
	}
    
    void helper(int i,int j,int row,int col,vector<vector<int>>& visited){
        if(i==row-1 && j==col-1)
		{
			totalpath++;
			return;
		}
        
        if(!IsSafe(i,j,row,col,visited)){
            return;
        }
        visited[i][j]=1;
        if(i+1<row)//down move
			helper(i+1,j,row,col,visited);
		if(j+1<col)//right  move
			helper(i,j+1,row,col,visited);
        visited[i][j]=0;
        return;
    }
    
    
    int uniquepathTP(int i,int j,vector<vector<int>>&dp){
        if(i==0 and j==0){
            return 1;
        }
        
        if(i<0 || j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        dp[i][j]=uniquepathTP(i-1,j,dp)+uniquepathTP(i,j-1,dp);
        
        return dp[i][j];
    }
    
    
    
    int uniquePaths(int m, int n) {
        // vector<vector<int>> visited(m,vector<int>(n,0));
        // helper(0,0,m,n,visited);
        // return totalpath;
        // int N = n + m -2;  //N=3
        // int r = m-1;       //right = 2
        // double res = 1;   //result = 1
        // for(int i=1;i<=r;i++) {
        //     res = res * (N-r+i)/i;
        // }
        // return (int)res;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return uniquepathTP(m-1,n-1,dp);
    }
};