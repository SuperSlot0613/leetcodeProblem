class Solution {
public:
    map<pair<int,int>, bool> m;  
    int count = 0;                
    void dfstravel(int v, vector<int> adj[], vector<bool> &vis)
    {
        vis[v] = true;
        for(auto u: adj[v])
        {
            if(vis[u] == false)
            {
                if(m[{v, u}] == true)  
                    count++;
                dfstravel(u, adj, vis);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections){
        vector<int> adj[n];      
        vector<bool> vis(n, false); 
        for(auto i: connections)   {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            m[{i[0], i[1]}] = true;    
        }
        dfstravel(0, adj, vis);
        return count;
    }
};