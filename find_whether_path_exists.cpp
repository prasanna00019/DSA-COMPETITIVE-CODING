// https://www.geeksforgeeks.org/problems/find-whether-path-exist5238/1?page=5&company=Adobe&sortBy=submissions
bool helper(vector<vector<int>>& grid, vector<vector<bool>>& visited, int s1, int s2, int e1, int e2) {
    if (s1 < 0 || s1 >= grid.size() || s2 < 0 || s2 >= grid[0].size() || grid[s1][s2] == 0 || visited[s1][s2]) {
        return 0;
    }
    if (s1 == e1 && s2 == e2) {
        return 1;
    }
 
   visited[s1][s2] = true;

    int total = helper(grid, visited, s1 + 1, s2, e1, e2) +
                 helper(grid, visited, s1, s2 + 1, e1, e2) +
                 helper(grid, visited, s1 - 1, s2, e1, e2) +
                 helper(grid, visited, s1, s2 - 1, e1, e2);

    return total;
}

bool is_Possible(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int emptysquare = 1;
    int s1, s2, e1, e2;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                s1 = i;
                s2 = j;
            } else if (grid[i][j] == 2) {
                e1 = i;
                e2 = j;
            } else if (grid[i][j] == 3) {
                emptysquare++;
            }
        }
    }

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    return helper(grid, visited, s1, s2, e1, e2) > 0 ? 1 : 0;
}
