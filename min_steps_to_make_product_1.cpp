// https://www.geeksforgeeks.org/problems/minimum-steps-to-make-product-equal-to-one/1
// Input:
// N = 3
// arr[] = {-2, 4, 0}
// Output:
// 5
// Explanation:
// We can change -2 to -1, 0 to -1 and 4 to 1.
// So, a total of 5 steps are required
// to update the elements such that
// the product of the final array is 1. 
  
int makeProductOne(int a[], int n) {
        // code here
        int pos=0;int neg=0;int zero=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                zero++;
            }
            else if(a[i]<0){
                neg++;
                ans=ans+(-1-a[i]);
            }
            else{
                pos++;;
                ans=ans+(a[i]-1);
            }
        }
        if(neg%2==0){
            ans+=zero;
        }
        else{
            if(zero>0){
                ans+=zero;
            }
            else{
                ans+=2;
            }
        }
        return ans;
    }
