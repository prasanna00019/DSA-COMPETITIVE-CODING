/*
Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:
Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.

Example 2:
Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is [2, 3, 4, 5] which gives product as 120.
*/

long long maxProduct(vector<int> arr, int n) {
	    // code here
	   long long ans=INT_MIN;
   long long product=1;
    
   for(int i=0;i<n;i++){
       product*=arr[i];
       ans=max(ans,product);
       if(arr[i]==0){product=1;}
   }
    
   product=1;
    
   for(int i=n-1;i>=0;i--){
       product*=arr[i];
       ans=max(ans,product);
       if(arr[i]==0){product=1;}
   }
   return ans;
	}
