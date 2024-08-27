// // https://www.geeksforgeeks.org/problems/maximum-difference-1587115620/1
// Given an integer array arr of integers, the task is to find the maximum absolute difference between the nearest
// left smaller element and the nearest right smaller element of every element in array arr. 
// If for any component of the arr, the nearest smaller element doesn't exist then consider it as 0.

// Examples :

// Input: arr = [2, 1, 8]
// Output: 1
// Explanation: left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1
// Input: arr = [2, 4, 8, 7, 7, 9, 3]
// Output: 4
// Explanation: left smaller array ls = [0, 2, 4, 4, 4, 7, 2], right smaller rs = [0, 3, 7, 3, 3, 3, 0]. Maximum Diff of abs(ls[i] - rs[i]) = abs(7 - 3) = 4

 int findMaxDiff(vector<int> &arr) {
       stack<int> s1, s2;
       int n=arr.size();
       vector<int> leftSmall(n);
       vector<int> rightSmall(n);
    // Construct leftSmall array
       leftSmall[0] = 0; // No left smaller for the first element
       s1.push(0);
       for (int i = 1; i < n; i++) {
        while (!s1.empty() && arr[s1.top()] >= arr[i]) {
            s1.pop();
        }
        if (s1.empty()) {
            leftSmall[i] = 0;
        } else {
            leftSmall[i] = arr[s1.top()];
        }
        s1.push(i);
    }
    // Construct rightSmall array
    rightSmall[n - 1] = 0; // No right smaller for the last element
    s2.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        while (!s2.empty() && arr[s2.top()] >= arr[i]) {
            s2.pop();
        }
        if (s2.empty()) {
            rightSmall[i] = 0;
        } else {
            rightSmall[i] = arr[s2.top()];
        }
        s2.push(i);
    }
    // Calculate the maximum absolute difference
    int maxDiff = 0;
    for (int i = 0; i < n; i++) {
        int diff = abs(leftSmall[i] - rightSmall[i]);
        maxDiff = max(maxDiff, diff);
    }
    return maxDiff;
    }
