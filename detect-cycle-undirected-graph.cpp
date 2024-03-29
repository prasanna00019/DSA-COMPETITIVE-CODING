/*
Detect cycle in an undirected graph
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. 
Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.
*/
bool detect(int src,vector<int>adj[],int vis[]){
      vis[src]=1;
      queue<pair<int,int>>q;
      q.push({src,-1});
      while(!q.empty()){
          int node=q.front().first;
          int parent=q.front().second;
          q.pop();
          for(auto adjacentnodes: adj[node]){
              if(!vis[adjacentnodes]){
                  vis[adjacentnodes]=1;
                  q.push({adjacentnodes,node});
              }
              else if(parent!=adjacentnodes){
                  return true;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)==true) return true;
            }
        }
        return false;
    }
