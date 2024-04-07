/*
There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. Count the number of ways,
the person can reach the top (order does matter).
Example 1:

Input:
n = 4
Output: 5
Explanation:
You can reach 4th stair in 5 ways. 
Way 1: Climb 2 stairs at a time. 
Way 2: Climb 1 stair at a time.
Way 3: Climb 2 stairs, then 1 stair
and then 1 stair.
Way 4: Climb 1 stair, then 2 stairs
then 1 stair.
Way 5: Climb 1 stair, then 1 stair and
then 2 stairs.
*/ 
int mod=1e9+7;
int countWays(int n)
    {
        // your code here
      vector<int>arr(n,0);
      arr[0]=1;arr[1]=2;
      for(int i=2;i<n;i++){
          arr[i]=(arr[i-1]+arr[i-2])%mod;
      }
     return arr[n-1];
    }
