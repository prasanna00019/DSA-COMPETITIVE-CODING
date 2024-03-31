/*Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

Example 1:

Input:
         5
       /   \
      1     1
     /       \
    2         2
Output: 
True
Explanation: 
Tree is mirror image of itself i.e. tree is symmetric
*/
bool helper(struct Node* l,struct Node* r){
        if(l==NULL || r==NULL){return l==r;}
        if(l->data!=r->data){return false;}
        return helper(l->left,r->right) && helper(l->right,r->left);
    }
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    
	    return root==NULL||helper(root->left,root->right);
    }
