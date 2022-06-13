class Solution {
public:
    
    int minEditdistanceTD(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=minEditdistanceTD(i-1,j-1,s1,s2,dp);
        }
        dp[i][j]=min({1+minEditdistanceTD(i,j-1,s1,s2,dp),1+minEditdistanceTD(i-1,j,s1,s2,dp),1+minEditdistanceTD(i-1,j-1,s1,s2,dp)});
        return dp[i][j];
    }
    
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // return minEditdistanceTD(n-1,m-1,s1,s2,dp);
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=0;i<=n;i++) dp[i][0]=i;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                     dp[i][j]=dp[i-1][j-1];
                }else{
                     dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});   
                }
            }
        }
        return dp[n][m];
    }
};