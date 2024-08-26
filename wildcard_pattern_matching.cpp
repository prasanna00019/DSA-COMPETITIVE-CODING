// Given two strings pattern and str which may be of different size, You have to return 1 if the wildcard pattern i.e. pattern, matches with str else return 0. All characters of the string str and pattern always belong to the Alphanumeric characters.

// The wildcard pattern can include the characters ? and *
// ‘?’ – matches any single character.
// ‘*’ – Matches any sequence of characters (including the empty sequence).

// Note: The matching should cover the entire str (not partial str).

// // https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1

 bool helper(string p, string s){
        vector<vector<bool>>dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0]=true;
        for(int j=0;j<p.size() && p[j]=='*';++j){
            dp[0][j+1]=true;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=p.size();j++){
                if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j]=(s[i-1]==p[j-1]|| p[j-1]=='?') && dp[i-1][j-1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
    int wildCard(string pattern , string str){
        return helper(pattern , str);
    }
