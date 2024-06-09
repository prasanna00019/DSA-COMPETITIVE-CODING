// https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
// Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum. You just need to return true/false depending 
// upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the driver code.

// Example 1:

// Input:
// n = 5
// arr = {4,2,-3,1,6}
// Output: 
// Yes
// Explanation: 
// 2, -3, 1 is the subarray with sum 0.

 bool subArrayExists(int arr[], int n)
    {
        map<int,int>mp;
        int maxlength=0;int current_sum=0;
        for(int i=0;i<n;i++){
              if(arr[i]==0){
                return 1;
            }
            current_sum+=arr[i];
            if(current_sum==0){
                return 1;
            }
            else{
                if(mp.find(current_sum)!=mp.end()){
                    return 1;
                }
                else{
                    mp[current_sum]=i;
                }
            }
        }
        if(maxlength==0){
            return 0;;
        }
        return 1;
    }
