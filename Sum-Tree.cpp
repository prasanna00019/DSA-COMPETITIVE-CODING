Sum Tree
/*
Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, 
its value is equal to the sum of its left subtree's value and its right subtree's value. 
Else return false.
An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0.
A leaf node is also considered a Sum Tree.
*/
int sum(Node* root){
       if(root==NULL) return 0;
       return root->data+sum(root->left)+sum(root->right);
   }
    bool isSumTree(Node* root)
    {
         // Your code here
             if (root == NULL || (root->left == NULL && root->right == NULL))
            return true;

        int leftSum = sum(root->left);
        int rightSum = sum(root->right);

        return (root->data == leftSum + rightSum) &&
               isSumTree(root->left) &&
               isSumTree(root->right);
    }
