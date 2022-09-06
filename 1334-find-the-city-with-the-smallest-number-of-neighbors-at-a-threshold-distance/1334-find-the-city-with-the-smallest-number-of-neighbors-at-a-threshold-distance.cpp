class Solution {
public:
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
       int dp[n][n];
        memset(dp,1e9+10,sizeof(dp));
        for(auto it: edges){
            int x=it[0], y=it[1], wt =it[2];
            dp[x][y]=wt;
            dp[y][x]=wt;
        }
        for(int i=0;i<n;i++) dp[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dp[i][k]!=INT_MAX and dp[k][j]!=INT_MAX)
                        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);                
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans=-1,min_cities_reachable=INT_MAX;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(i!=j and dp[i][j]<=distanceThreshold) temp+=1;
            }
            if(temp<=min_cities_reachable)
                min_cities_reachable=temp,ans=i;
        }
        return ans;
        
    }
};