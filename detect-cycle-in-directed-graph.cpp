 bool dfs(int node,vector<int>adj[],int vis[],int pathVis[]){
      vis[node]=1;
      pathVis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it]){
              if(dfs(it,adj,vis,pathVis)){
                  return true;
              }
          }
              else if(pathVis[it]){
                  return true;
              }
          
      }
      
      pathVis[node]=0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)==true) return true;
            }
            
        }
        return false;}
