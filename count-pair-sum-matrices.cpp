/*
Count pairs Sum in matrices

Given two sorted matrices mat1 and mat2 of size n x n of elements.
Each matrix contains numbers arranged in strictly ascending order, with each row sorted from left to right, and the last element of a row being smaller than the first element of the next row.
You're given a target value, x, your task is to find and count all pairs {a, b} such that a is from mat1 and b is from mat2 where sum of a and b is equal to x.
*/

int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    int count=0;
	    set<int>s1;
	    // Your code goes here
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            s1.insert(mat1[i][j]);
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            int x1=x-mat2[i][j];
	            if(s1.find(x1)!=s1.end()){
	                count++;
	            }
	        }
	    }
	    return count;
	}
