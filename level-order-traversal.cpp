/*
PRINT THE LEVEL ORDER TRAVERSAL OF A BINARY TREE . STORE IT IN VECTOR , RETURN NSWER IN VECTOR
*/
vector<int> levelOrder(Node* root)
    {
      //Your code here
      queue<Node*>q;
      q.push(root);
      vector<int>ans;
      while(!q.empty()){
          Node* f=q.front();
          q.pop();
          ans.push_back(f->data);
          if(f->left){
              q.push(f->left);
          }
          if(f->right){
              q.push(f->right);
          }
          
      }
      return ans;
    }
