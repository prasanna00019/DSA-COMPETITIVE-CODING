// https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
// You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.
// Example 1:
// Input:
// n = 6
// arr[] = {0,0,5,5,0,0}
// Output: 6
// Explanation: The 6 subarrays are 
// [0], [0], [0], [0], [0,0], and [0,0].

// Example 2:
// Input:
// n = 10
// arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
// Output: 4
// Explanation: The 4 subarrays are [-1 -3 4]
// [-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

 long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
         long long ans = 0;
    map<int, int> mp;
    int current_sum = 0;
    mp[0] = 1; // Initialize with 1, as there's always a subarray with sum 0 (empty subarray)
    for (int i = 0; i < n; i++) {
        current_sum += arr[i];
        if (mp.find(current_sum) != mp.end()) {
            ans += mp[current_sum]; // Add the count of previous occurrences
        }
        mp[current_sum]++; // Increment the count of current sum
    }
    return ans;
    }
