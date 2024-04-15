/*
Sum of Products
Given an array arr[] of size n. Calculate the sum of Bitwise ANDs ie: 
calculate sum of arr[i] & arr[j] for all the pairs in the given array arr[] where i < j.
Example 1:
Input:
n = 3
arr = {5, 10, 15}
Output:
15
Explanation:
The bitwise Ands of all pairs where i<j are (5&10) = 0, (5&15) = 5 and (10&15) = 10.
Therefore, the total sum = (0+5+10) = 15.
*/
  long long pairAndSum(int n, long long arr[]) {
        // code here
        long long sum=0;
        for(int i=0;i<=31;i++){
            long long k=0;
            for(int j=0;j<n;j++){
                if(((arr[j]>>i)&1)==1){
                    k++;
                }
            }
            long long pairs=k*(k-1)/2;
            sum+=(1<<i)*pairs;
        }
        return sum;
    }
 
