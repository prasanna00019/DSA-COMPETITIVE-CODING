/*Given two non-decreasing sorted arrays, ‘A’ and ‘B’, having ‘N’ and ‘M’ elements, respectively.
You must merge these arrays, ‘A’ and ‘B’, into a sorted array without using extra space. Of all the 'N + M' sorted elements, 
array 'A' should contain the first 'N' elements, and array 'B' should have the last 'M' elements.
Note:
You must perform the merge operation in place and must not allocate any extra space to merge the two arrays.
For example:
When ‘N’ = 4, ‘A’ = {1, 4, 5, 7} and ‘M’ = 3, ‘B’ = {2, 3, 6}. 
We can merge these two arrays into {1, 2, 3, 4, 5, 6, 7} (The elements of ‘A’ are {1, 2, 3, 4} ).
Hence, the answer is {1, 2, 3, 4, 5, 6, 7}.

CODE C++;*/

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	 int n = a.size();
    int m = b.size();
    int i = 0, j = 0, k = n-1;
	
    // Iterating Over A & B
    while(i <= k && j < m){
        if(a[i] < b[j]) // No Swap needed
            i++;
        else{
            swap(a[k], b[j]);
            j++;
            k--;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
	
}
