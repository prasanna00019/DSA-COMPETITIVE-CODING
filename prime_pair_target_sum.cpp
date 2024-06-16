// https://www.geeksforgeeks.org/problems/sum-of-prime4751/1
// Given a number n, find out if n can be expressed as a+b, where both a and b are prime numbers. If such a pair exists, return the values of a and b, otherwise return [-1,-1] as an array of size 2.
// Note: If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, and a < c then  [a, b] is considered as our answer.

 vector<int> getPrimes(int n) {
        vector<int>ans;
        if(n<2){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        vector<bool>prime(n+1,true);
        prime[0]=false;prime[1]=false;
    
        for(int p=2;p<=sqrt(n);p++){
            if(prime[p]){
                for(int i=p*p;i<=n;i+=p){
                    prime[i]=false;
                }
            }
        }
         int i=2;int j=n;
         while(!prime[j]){j--;}
         while(i<=j){
             int sum=i+j;
             if(sum==n){return {i,j};}
             else if (sum>n){
                 j--;
                 while(!prime[j]){j--;}
             }
             else{
                 i++;
                 while(!prime[i]){i++;}
             }
         }
        return {-1,-1};
    }
