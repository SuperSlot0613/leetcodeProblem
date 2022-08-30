class Solution {
public:
    void dfstravel(int node,vector<int> adj[],vector<vector<int>>&ans,vector<int> res,vector<int> vis,int n){
        res.push_back(node);
        vis[node]=1;
        if(node==n-1){
            ans.push_back(res);
            return;
        }
        for(auto it:adj[node]){
            if(!vis[it]){
                dfstravel(it,adj,ans,res,vis,n);
            }
        }
        res.pop_back();
        vis[node]=0;
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
           for(int j=0;j<graph[i].size();j++){
               adj[i].push_back(graph[i][j]);
           } 
        }
        vector<int> vis(n+1,0);
        vector<vector<int>> ans;
        vector<int> res;
        dfstravel(0,adj,ans,res,vis,n);
        return ans;
    }
};