/*
Sum of all substrings of a number
Given an integer s represented as a string, the task is to get the 
sum of all possible sub-strings of this string.
As the answer will be large, return answer modulo 109+7. 

Note: The number may have leading zeros.
Example 1:
Input:
s = "1234"
Output: 
1670
Explanation: 
Sum = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234 = 1670
Example 2:

Input:
s = "421"
Output: 
491
Explanation: 
Sum = 4 + 2 + 1 + 42 + 21 + 421 = 491
*/

long long sumSubstrings(string s){
        const int mod=1000000007;
        // your code here
        long long ans=0;
       long long temp=0;
       int n=s.size();
       for(int i=0;i<n;i++){
           temp=temp*10+(i+1)*(s[i]-'0');
           temp%=mod;
         //  cout<<temp<<" ";
           ans+=temp;
          // cout<<ans<<" ";
           ans%=mod;
       }
       return ans;
    }
