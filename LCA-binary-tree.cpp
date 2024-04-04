/*
Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes.
We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Example 1:

Input:
n1 = 2 , n2 = 3  
       1 
      / \ 
     2   3
Output: 1
Explanation:
LCA of 2 and 3 is 1.
Example 2:

Input:
n1 = 3 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 2
Explanation:
LCA of 3 and 4 is 2. 
Example 3:

Input:
n1 = 5 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 5
Explanation:
LCA of 5 and 4 is 5. 
 */
Node* lca(Node* root ,int n1 ,int n2 )
    {
      if(root==NULL ||root->data==n1 || root->data==n2){
          return root;
      }
      Node* l=lca(root->left,n1,n2);
      Node* r=lca(root->right,n1,n2);
      if(l==NULL) return r;
      if(r==NULL) return l;
      else return root;
    }
