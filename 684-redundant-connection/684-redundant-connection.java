class Solution {
  public boolean hasCycle(int [][]graph,boolean[]vis,int u,int parent){
        vis[u]=true;
        for(int i=0;i<graph.length;i++){
           if(graph[u][i]==1){
              if(vis[i]==false){
                  if(hasCycle(graph,vis,i,u))
                     return true;
              }                
              else if(i!=parent){
                 return true;
              }   
            } 
        }
        return false;
    }
    public int[] findRedundantConnection(int[][] edges) {
        int n=edges.length;
        int [][]graph=new int[n][n];
        boolean []vis;
        for(int []edge:edges){
            vis=new boolean[n];
            graph[edge[0]-1][edge[1]-1]=1;
            graph[edge[1]-1][edge[0]-1]=1;
            if(hasCycle(graph,vis,edge[0]-1,-1)){
               return edge;  
            }
           
        }
        return new int[0];
    }
}