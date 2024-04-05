/*
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8
*/
 vector<int>helper(Node* root){
         if(!root) {
             return {INT_MAX,INT_MIN,0};
         }
         if(root->left==NULL && root->right==NULL){
             return {root->data,root->data,1};
         }
         vector<int>left=helper(root->left);
         vector<int>right=helper(root->right);
             vector<int> ans(3, 0);


         if(left[1]<root->data  && right[0]>root->data){
             ans[0]=min(left[0],min(right[0],root->data));
             ans[1]=max(right[1],max(left[1],root->data));
             ans[2]=1+left[2]+right[2];
             return ans;
         }
         ans[0]=INT_MIN;
         ans[1]=INT_MAX;
         ans[2]=max(left[2],right[2]);
         return ans;
     }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	return helper(root)[2];
    }
