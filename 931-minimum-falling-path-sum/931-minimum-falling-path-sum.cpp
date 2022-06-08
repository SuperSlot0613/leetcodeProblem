class Solution {
public:
    
    int minFallingPathTD(int i,int j,int m,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0 || j>=m) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
      
        int down=matrix[i][j]+minFallingPathTD(i-1,j,m,matrix,dp);
        int ld=matrix[i][j]+minFallingPathTD(i-1,j-1,m,matrix,dp);
        int rd=matrix[i][j]+minFallingPathTD(i-1,j+1,m,matrix,dp);
        dp[i][j]=min({down,ld,rd});
        return dp[i][j];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        // int mini=INT_MAX;
        // for(int j=0;j<m;j++){
        //     mini=min(mini,minFallingPathTD(n-1,j,m,matrix,dp));
        // }
        
        for(int j=0;j<m;j++) dp[0][j]=matrix[0][j];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=matrix[i][j]+dp[i-1][j];
                int ld=matrix[i][j];
                if(j-1>=0) ld=ld+dp[i-1][j-1];
                else ld+=1e9;
                int rd=matrix[i][j];
                if(j+1<m) rd=rd+dp[i-1][j+1];
                else rd+=1e9;
                dp[i][j]=min({up,ld,rd});
            }
        }
        int minimi=dp[n-1][0];
        for(int i=1;i<m;i++){
            minimi=min(minimi,dp[n-1][i]);
        }
        return minimi;
    }
};