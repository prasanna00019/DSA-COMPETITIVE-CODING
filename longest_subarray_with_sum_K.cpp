// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

// Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

 

// Example 1:
 

// Input :
// A[] = {10, 5, 2, 7, 1, 9}
// K = 15
// Output : 4
// Explanation:
// The sub-array is {5, 2, 7, 1}.\

 int lenOfLongSubarr(int arr[],  int n, int K) 
    { 
        // Complete the function
        map<long long int,int>mp;
        int maxlength=0;long long int current_sum=0;
        for(int i=0;i<n;i++){
            current_sum+=arr[i];
            if(current_sum==K){
                maxlength=max(maxlength,i+1);
            }
        
                if(mp.find(current_sum-K)!=mp.end()){
                    maxlength=max(maxlength,i-mp[current_sum-K]);
                }
                 if(mp.find(current_sum)==mp.end()){
                    mp[current_sum]=i;
                }
            
        }
        return maxlength;
    } 
