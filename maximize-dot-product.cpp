/*
Maximize dot product
Given two arrays a and b of positive integers of size n and m where n >= m, 
the task is to maximize the dot product by inserting zeros in the second array but you cannot disturb the order of elements.

Dot product of array a and b of size n is a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1].

Example 1:

Input: 
n = 5, a[] = {2, 3, 1, 7, 8} 
m = 3, b[] = {3, 6, 7}
Output: 
107
Explanation: 
We get maximum dot product after inserting 0 at first and third positions in second array.
Therefore b becomes {0, 3, 0, 6, 7}. 
Maximum dot product = 2*0 + 3*3 + 1*0 + 7*6 + 8*7 = 107.
*/ 
int helper(int i,int j,int a[],int b[],int n,int m,int diff,vector<vector<int>>&dp,int s1,int s2){
	    if(i==n || j==m )return 0;
	    if(dp[i][j]!=-1) return dp[i][j];
	    //int sum1=0;int sum2=0;
	    if(diff){
	        s1= helper(i+1,j,a,b,n,m,diff-1,dp,s1,s2);
	    }
	    s2=a[i]*b[j]+helper(i+1,j+1,a,b,n,m,diff,dp,s1,s2);
	    return dp[i][j]=max(s1,s2);
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
	vector<vector<int>> dp(n,vector<int>(m,-1));
	int s1=0;int s2=0;
		return helper(0,0,a,b,n,m,n-m,dp,s1,s2);
    
	}
