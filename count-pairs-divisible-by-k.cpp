
long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        int count[K]={0};
       long long  int ans=0;
        for(int i=0;i<n;i++){
            int rem=A[i]%K;
            ans+=count[(K-rem)%K];
            count[rem]++;
        }
        return ans;
    }

// Input : 
// A[] = {2, 2, 1, 7, 5, 3}, K = 4
// Output : 5
// Explanation : 
// There are five pairs possible whose sum
// is divisible by '4' i.e., (2, 2), 
// (1, 7), (7, 5), (1, 3) and (5, 3)
// Example 2:

// Input : 
// A[] = {5, 9, 36, 74, 52, 31, 42}, K = 3
// Output : 7 
// Explanation : 
// There are seven pairs whose sum is divisible by 3, 
// i.e, (9, 36), (9,42), (74, 52), (36, 42), (74, 31), 
// (31, 5) and (5, 52).
