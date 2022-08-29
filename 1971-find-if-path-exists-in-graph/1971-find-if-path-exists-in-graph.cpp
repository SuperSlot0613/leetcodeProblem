class Solution {
public:
    
     bool dfs(vector<int> adj[],int s,int d,vector<bool>& vis){
        vis[s]=true;
        if(s==d)
            return true;
        for(int v: adj[s]){
            if(vis[v]==false){
                if(dfs(adj,v,d,vis))
                    return true;
            }     
        }
        return false;
    }
    void mg(vector<vector<int>>& edges,vector<int> adj[]){
        for(vector<int> x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<int> adj[n];
        mg(edges,adj);
        vector<bool> vis(n,false);
        bool res=dfs(adj,s,d,vis);
        return res;
    }
};