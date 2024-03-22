/*Diagonal sum in binary tree

Consider Red lines of slope -1 passing between nodes (in following diagram). 
The diagonal sum in a binary tree is the sum of all node datas lying between these lines. Given a Binary Tree of size n, print all diagonal sums.

https://www.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1
  
For the following input tree, output should be 9, 19, 42.
9 is sum of 1, 3 and 5.
19 is sum of 2, 6, 4 and 7.
42 is sum of 9, 10, 11 and 12.*/

void solve(Node* root,map<int,int>&mp,int level){
        if(!root) return;
        mp[level]+=root->data;
        solve(root->left,mp,level+1);
        solve(root->right,mp,level);
    }
    vector<int> diagonalSum(Node* root) {
        // Add your code here
        map<int,int>mp;
        solve(root,mp,0);
        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
