 // All Ancestors of a Node in a Directed Acyclic Graph
class Solution {
public:
   void dfs(vector<vector<int>>&graph,int parent,int curr,vector<vector<int>>&res,
   vector<bool>&visit){
    visit[curr]=true;
    for(int adj:graph[curr]){
        if(!visit[adj]){
            res[adj].push_back(parent);
            dfs(graph,parent,adj,res,visit);
        }
    }
   }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<vector<int>>res(n);
        for(const auto x:edges){
            graph[x[0]].push_back(x[1]);
        }
        for(int i=0;i<n;i++){
            vector<bool>visit(n,false);
            dfs(graph,i,i,res,visit);
        }
        for(int i=0;i<n;i++){
            sort(res[i].begin(),res[i].end());
        }
        return res;
    }
};
