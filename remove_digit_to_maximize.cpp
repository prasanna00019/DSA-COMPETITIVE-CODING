// Remove Digit From Number to Maximize Result
// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/
class Solution {
public:
    string removeDigit(string number, char digit) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        string ans="0";
        int n=number.size();
        for(int i=0;i<n;i++){
            if(number[i]==digit){
                string temp=number.substr(0,i)+number.substr(i+1,n);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};
