// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

// Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.


void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    int m=grid.size();int n=grid[0].size();
    while(!q.empty()){
        int row=q.front().first;int col=q.front().second;
        q.pop();
        for(int k1=-1;k1<=1;k1++){
            for(int k2=-1;k2<=1;k2++){
              
                int nrow=row+k1;int ncol=col+k2;
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and
                grid[nrow][ncol]=='1' and !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;q.push({nrow,ncol});
                }
            }
        }
    }
   }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
          int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int c=0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(!vis[row][col] and grid[row][col]=='1'){
                    c++;bfs(row,col,vis,grid);
                }
            }
        }
        return c;
    }
