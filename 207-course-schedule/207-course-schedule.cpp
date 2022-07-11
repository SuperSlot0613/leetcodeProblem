class Solution {
public:
    
    bool cycleexist(int i,vector<int> &vis,vector<int> &dfsvis,vector<int> prerequisites[]){
        vis[i]=1;
        dfsvis[i]=1;
        for(auto it:prerequisites[i]){
            if(!vis[it]){
                if(cycleexist(it,vis,dfsvis,prerequisites)){
                    return true;
                }
            }else if(dfsvis[it]){
                return true;
            }
        }
        dfsvis[i]=0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        
        vector<int> adj[numCourses];
        for(int i=0;i<p.size();i++){
            int u=p[i][0];
            int v=p[i][1];
            adj[u].push_back(v);
        }
        vector<int> vis(numCourses,0),dfsvis(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(cycleexist(i,vis,dfsvis,adj)){
                    return false;
                }
            }
        }
        return true;
        
    }
};