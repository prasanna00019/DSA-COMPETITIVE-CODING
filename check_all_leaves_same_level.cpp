bool check(Node*root){
 if(root==NULL){return 1;}
  queue<Node*>q1;
  q1.push(root);
  int flag=0;
  while(!q1.empty()){
   int n=q1.size();
    for(int i=1;i<=n;i++){
     Node* temp=q1.front();
      q1.pop();
      if(temp->left){
       q1.push(temp->left);
      }
      if(temp->right){
       q1.push(temp->right);
      }
      if(temp->left==NULL && temp->right==NULL){
       flag=1;
      }
    }
    if(flag && !q1.empty()){
    return 0;
    }
  }
  return 1;
}
