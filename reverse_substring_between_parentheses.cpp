// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>s1;
        string result;
        for(char x:s){
            if(x=='('){
                s1.push(result.length());
            }
            else if(x==')'){
                int start=s1.top();
                s1.pop();
                reverse(result.begin()+start,result.end());
            }
            else{
                result+=x;
            }
        }
        return result;
    }
};
