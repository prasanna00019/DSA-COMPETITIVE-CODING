// // https://leetcode.com/problems/path-with-maximum-probability/?envType=daily-question&envId=2024-08-27
// You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge,
// connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
// Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
// If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

// Example 1:
// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
// Output: 0.25000
// Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

// Example 2:
// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
// Output: 0.30000

// CPP:
  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    vector<vector<pair<int,double>>>adjList(n);
    fo(int i=0;i<edges.size();i++){
      adjList[edges[i][0]].push_back({edges[i][1], succProb[i]});
      adjList[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    priority_queue<pair<double,int>>pq;
    vector<double>dis(n,0.0);
    dis[start_node]=1.0;
    pq.push({1.0,start_node});
    while(!pq.empty()){
      int node=pq.top().second;
      double currProb=pq.top().first;
      pq.pop();
      if(currProb< dis[node]) continue;
      for(auto & neighbour:adjList[node]){
       int nextNode= neighbour.first;
       double Nextprob=neighbour.second;
        if(dis[node]*Nextprob>dis[nextnode]){
          dis[nextnode]=dis[node]*Nextprob;
          pq.push({dis[nextNode],nextNode});
        }
        
      }
    }
    return dis[nextNode];
  }
