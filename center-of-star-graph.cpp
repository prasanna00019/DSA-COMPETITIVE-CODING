// https://leetcode.com/problems/find-center-of-star-graph/description/?envType=daily-question&envId=2024-06-27

 int findCenter(vector<vector<int>>& edges) {
    vector<vector<int>> adj(edges.size() + 1); // Initialize adj with a size of edges.size() + 1
    int a;
    for(auto x: edges){
        adj[x[0] - 1].push_back(x[1] - 1); // Subtract 1 because vector indices start from 0
        adj[x[1] - 1].push_back(x[0] - 1);
    }
    for(int i=0;i<adj.size();i++){
        if(adj[i].size()==adj.size()-1){
           a=i+1; // Add 1 because node indices start from 1
        }
    }
    return a;
}
