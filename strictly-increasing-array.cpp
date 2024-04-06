/*
Strictly Increasing Array

Given an array nums of n positive integers. Find the minimum number of operations required to modify the array such that array
elements are in strictly increasing order (nums[i] < nums[i+1]).
Changing a number to greater or lesser than original number is counted as one operation.

Note: Array elements can become negative after applying operation.

Example 1:

Input:
n = 6
nums = [1, 2, 3, 6, 5, 4]
Output: 
2
Explanation: 
By decreasing 6 by 2 and increasing 4 by 2, nums will be like [1, 2, 3, 4, 5, 6] which is stricly increasing.
Example 2:

Input: 
n = 4
nums = [1, 1, 1, 1]
Output: 
3
Explanation: 
One such array after operation can be [-2, -1, 0, 1]. We require atleast 3 operations for this example.
*/  
int min_operations(vector<int>& nums) {
        // Code here
        int n=nums.size();
        int temp=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
            if(nums[i]-nums[j]>=i-j){
                dp[i]=max(dp[i],dp[j]+1);
                temp=max(temp,dp[i]);
                
            }
        }
        }
        return n-temp;
    }
