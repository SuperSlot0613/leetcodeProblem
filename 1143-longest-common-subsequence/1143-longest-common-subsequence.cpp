class Solution {
public:
    
    int LCS(string text1,string text2,int i,int j){
        if(i==text2.size() || j==text1.size()){
            return 0;
        }
        else if(text2[i]==text1[j]){
            return 1+LCS(text1,text2,i+1,j+1);
        }
        else{
            return max(LCS(text1,text2,i+1,j),LCS(text1,text2,i,j+1));
        }
    }
    
    int lcs(string X, string Y, int i, int j,
        vector<vector<int> >& dp)
    {
        if (i == X.size() || j == Y.size())
            return dp[i][j]=0;
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (X[i] == Y[j])
            return dp[i][j] = 1 + lcs(X,Y,i+1,j+1,dp);

        return dp[i][j] = max(lcs(X, Y, i, j+1, dp),
                              lcs(X, Y, i+1, j, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};