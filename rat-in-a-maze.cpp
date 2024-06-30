// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1?page=1&difficulty=Medium&status=unsolved&sortBy=submissions
 void helper(int i,int j,vector<vector<int>>m,int n, string move,
    vector<string>&ans,vector<vector<int>>visited){
        if(i==n-1 and j==n-1){
            ans.push_back(move);return;
        }
        visited[i][j]=1;
        // Move Left
        if (j - 1 >= 0 && m[i][j - 1] == 1 && visited[i][j - 1] == 0) {
            helper(i, j - 1, m, n, move + 'L', ans, visited);
        }
            if (i + 1 < n && m[i + 1][j] == 1 && visited[i + 1][j] == 0) {
            helper(i + 1, j, m, n, move + 'D', ans, visited);
        }


        // Move Right
        if (j + 1 < n && m[i][j + 1] == 1 && visited[i][j + 1] == 0) {
            helper(i, j + 1, m, n, move + 'R', ans, visited);
        }

        // Move Up
        if (i - 1 >= 0 && m[i - 1][j] == 1 && visited[i - 1][j] == 0) {
            helper(i - 1, j, m, n, move + 'U', ans, visited);
        }
        visited[i][j]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
      vector<string>ans;
      vector<vector<int>>visited(n,vector<int>(n,0));
      if(m[0][0]==1)  helper(0,0,m,n,"",ans,visited);
      return ans;
    }
