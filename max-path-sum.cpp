Maximum path sum
https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1?page=4&category=Tree,Binary%20Search%20Tree&sortBy=submissions
Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

Example 1:

Input:
     10
    /  \
   2   -25
  / \  /  \
 20 1  3  4
Output: 32
Explanation: Path in the given tree goes
like 10 , 2 , 20 which gives the max
sum as 32.

int helper(Node*root,int &ans){
if(root==NULL){return 0;}
int l=max(0,helper(root->left,ans));
int r=max(0,helper(root->right,ans);
ans=max(ans,val+l+r);
return max(l,r)+val;
}
int findMaxSum(Node* root)    {
        // Your code goes here
        int ans=INT_MIN;
        helper(root,ans);
        return ans;
}
