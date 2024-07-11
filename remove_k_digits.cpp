// https://leetcode.com/problems/remove-k-digits/description/
string removeKdigits(string S, int k) {
             int n=S.size();
     stack<char>s1;
     for(char c:S){
         while(!s1.empty() && k>0 && s1.top()>c){
             s1.pop(); k-=1;
         }
         if(!s1.empty() || c!='0'){
             s1.push(c);
         }
         
     }
     while(!s1.empty() && k--){
         s1.pop();
     }
     if(s1.empty()){
         return "0";
     }
     while(!s1.empty()){
         S[n-1]=s1.top();
         s1.pop();
         n-=1;
     }
     return S.substr(n);

    }
