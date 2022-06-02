class Solution {
public:
 
    int longestPalindromeSubseq(string s) {
        string str=s;
        reverse(str.begin(),str.end());
        int n=str.size();
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==str[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
        
    }
};