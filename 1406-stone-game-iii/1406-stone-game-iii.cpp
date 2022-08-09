class Solution {
public:
    // int dp[50001];
    // int helper(int i,vector<int>s){
    //     if(i>=s.size()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     else{
    //         int ans=INT_MIN;
    //         ans=max(ans,s[i]-helper(i+1,s));
    //         if(i+1<s.size()){
    //              ans=max(ans,s[i]+s[i+1]-helper(i+2,s));
    //         }
    //         if(i+2<s.size()){
    //             ans=max(ans,s[i]+s[i+1]+s[i+2]-helper(i+3,s));
    //         }
    //         dp[i]=ans;
    //         return dp[i];
    //     }
    // }
    
    string stoneGameIII(vector<int>& s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        int i=n-1;
        while(i>=0){
            int ans=INT_MIN;
            ans=max(ans,s[i]-dp[i+1]);
            if(i+1<s.size()){
                 ans=max(ans,s[i]+s[i+1]-dp[i+2]);
            }
            if(i+2<s.size()){
                ans=max(ans,s[i]+s[i+1]+s[i+2]-dp[i+3]);
            }
            dp[i]=ans;
            i--;
        }
        int alice=dp[0];
        if(alice>0) return "Alice";
        if(alice==0) return "Tie";
        return "Bob";
    }
};