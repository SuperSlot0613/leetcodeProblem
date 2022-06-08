int dp[51][51][51][51];
class Solution {
public:
    int n,m;
    int cherryPickup(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
    
        memset(dp,-1,sizeof(dp));
        
        int ans=find(0,0,0,0,grid);    
        
        if(ans<0)
            return 0;
        
        return ans;
        
    }
    
    int find(int i1,int j1,int i2,int j2,vector<vector<int>>& grid){
        
    if(i1>=n || j1>=m || i2>=n || j2>=m || i1<0 || j1<0 || i2<0 || j2<0 || grid[i1][j1]==-1 || grid[i2][j2]==-1){
            return -1e6;
        }
        
        if(i1==n-1 && j1==m-1){
            return grid[i1][j1];
        }
        
        if(i2==n && j2==m-1){
            return grid[i2][j2];
        }
        
        if(dp[i1][j1][i2][j2]!=-1)
            return dp[i1][j1][i2][j2];
        
        int mx=-1e6;
        
        int cher;
        
        if(i1==i2 && j1==j2)                   // both on the same cell, count it once
            cher=grid[i1][j1];
        else
            cher=grid[i1][j1]+grid[i2][j2];

        
        mx=max({mx,cher+find(i1,j1+1,i2,j2+1,grid),  //[LL]
                cher+find(i1,j1+1,i2+1,j2,grid),     //[LD]
                cher+find(i1+1,j1,i2,j2+1,grid),     //[D,L]
                cher+find(i1+1,j1,i2+1,j2,grid)});    //[D,D]
        
        return dp[i1][j1][i2][j2]=mx;
        
    }
};