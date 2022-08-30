class Solution {
public:
    
    void dfstravel(int node,vector<int> adj[],vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfstravel(it,adj,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n+1];
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(i==j){
                    continue;
                }
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        vector<int> vis(n+1,0);
        int count=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                count++;
                dfstravel(i,adj,vis);
            }
        }
        return count;
        
    }
};