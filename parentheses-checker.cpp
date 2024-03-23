/*
Parenthesis Checker

Given an expression string x. 
Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).
*/
bool ispar(string x)
    {
       stack<char>st1;
       for(int i=0;i<x.size();i++){
           if(x[i]=='(' || x[i]=='['|| x[i]=='{'){
               st1.push(x[i]);
           }
           else if(!st1.empty() && x[i]==')' && st1.top()=='('){
               st1.pop();
           }
             else if(!st1.empty() && x[i]=='}' && st1.top()=='{'){
               st1.pop();
           }
             else if(!st1.empty() && x[i]==']' && st1.top()=='[')
             {
               st1.pop();
             }
             else{
                st1.push(x[i]);
            }
       }
       return st1.empty();
    }
