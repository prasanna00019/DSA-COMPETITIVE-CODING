// Given a BST with unique node values, transform it into greater sum tree where each node contains sum of all nodes greater than that node.
void transformTree(struct Node *root)
    {
      if(root==NULL) return;
        transformTree(root->right);
        int x=root->data;
        root->data=sum;
        sum+=x;
        transformTree(root->left);    
        
    }
