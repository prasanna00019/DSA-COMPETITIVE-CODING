bool solve(Node* root,int min ,int max){
if(root==NULL){return true;}
  return root->data > min && root->data <max && solve(root->left,min,root->data) && solve(root->right,root->data,max) ;
}
bool isBST(Node* root){
 return solve(root->left,INT_MIN,root->data) && solve(root->right,root->data,INT_MAX);
}
