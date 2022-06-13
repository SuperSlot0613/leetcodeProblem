class Solution {
public:
    
    
    int minEditdistanceTD(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(s2[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j] || s2[j]=='?'){
            return dp[i][j]=minEditdistanceTD(i-1,j-1,s1,s2,dp);
        }
        if(s2[j]=='*'){
            return dp[i][j]=minEditdistanceTD(i,j-1,s1,s2,dp) || minEditdistanceTD(i-1,j,s1,s2,dp);
        }
        return dp[i][j]=false;
    }
    
    bool isMatch(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return minEditdistanceTD(n-1,m-1,s1,s2,dp);
    }
};