// https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1

// Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.


// Example 1:
// Input:
// N = 5
// Arr = {10 , 2, -2, -20, 10}
// k = -10
// Output: 3
// Explaination: 
// Subarrays: arr[0...3], arr[1...4], arr[3..4]
// have sum exactly equal to -10.

// Example 2:
// Input:
// N = 6
// Arr = {9, 4, 20, 3, 10, 5}
// k = 33
// Output: 2
// Explaination: 
// Subarrays : arr[0...2], arr[2...4] have sum
// exactly equal to 33.

 int findSubArraySum(int arr[], int n, int k)
    {
        map<int,int>mp;int ans=0;
        mp[0]=1;
        int current_sum=0;
        for(int i=0;i<n;i++){
         current_sum+=arr[i];
            if(mp.find(current_sum-k)!=mp.end()){
                ans+=mp[current_sum-k];
            }
            mp[current_sum]++;
        }
        return ans;
    }
