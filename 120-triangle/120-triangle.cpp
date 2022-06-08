class Solution {
public:
    
    int minimumPathTD(int i,int j,vector<vector<int>> triangle,vector<vector<int>>& dp){
        if(i==triangle.size()-1) return triangle[triangle.size()-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=triangle[i][j]+minimumPathTD(i+1,j,triangle,dp);
        int dia=triangle[i][j]+minimumPathTD(i+1,j+1,triangle,dp);
        dp[i][j]=min(down,dia);
        return dp[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        // return minimumPathTD(0,0,triangle,dp);
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int dia=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,dia);
            }
        }
        return dp[0][0];
    }
};