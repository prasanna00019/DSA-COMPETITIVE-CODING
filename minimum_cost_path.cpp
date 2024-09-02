https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1

    int minimumCostPath(vector<vector<int>>& grid) 
    {
     int n=grid.size();
      int m=grid[0].size();
      vector<pair<int,int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
      vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = grid[0][0];
      while(!pq.empty()){
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        int currCost=pq.top().first;
        pq.pop();
        if(x==n-1 and y==m-1){
          return currCost;
        }
        for(auto dir:directions){
         int newX=x+dir.first;
          int newY=y+dir.second;
            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                int newCost = currentCost + grid[newX][newY];
                
                // If a cheaper path to the cell is found, update the distance and push it to the queue
                if (newCost < dist[newX][newY]) {
                    dist[newX][newY] = newCost;
                    pq.push({newCost, {newX, newY}});
                }
            }
          
        }
        
      }
      return -1;
    }
