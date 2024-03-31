/*
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. 
The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. 
If Matrix[i][j]=-1, it means there is no edge from i to j.
Do it in-place.

Example 1:
Input: matrix = {{0,25},{-1,0}}
Output: {{0,25},{-1,0}}

Example 2:
Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}
Output: {{0,1,7},{1,0,6},{-1,-1,0}}
*/
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    for(int i =0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){matrix[i][j]=1e9;}
	            //if(i==j){matrix[i][j]=0;}
	        }
	    }
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}
