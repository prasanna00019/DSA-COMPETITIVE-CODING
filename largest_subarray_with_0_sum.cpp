// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?page=3&sortBy=submissions
// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Example 1:

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7

  int maxLen(vector<int>&arr,int n){
        map<int,int>mp;
        int maxlength=0;int current_sum=0;
        for(int i=0;i<n;i++){
            current_sum+=arr[i];
            if(current_sum==0){
                maxlength=max(maxlength,i+1);
            }
            else{
                if(mp.find(current_sum)!=mp.end()){
                    maxlength=max(maxlength,i-mp[current_sum]);
                }
                else{
                    mp[current_sum]=i;
                }
            }
        }
        return maxlength;
    }
