bool special(Node *root){
       if(root->left==NULL and root->right==NULL){
           return true;
       }
       return false;
   }
   int helper(Node* root,int &ans){
       if(root==NULL){return 0;}
       if(special(root)) {return root->data;}
       
       else{
           int x=helper(root->left,ans);
           int y=helper(root->right,ans);
           if(root->left and root->right){
           ans=max(ans,x+y+root->data);
           return max(x,y)+root->data;}
           if(root->left==NULL){
               return y+root->data;
           }
           else{
               return x+root->data;
           }
       }
   }
    int maxPathSum(Node* root)
    {
        int ans=INT_MIN;
        int x=helper(root,ans);
        if(root->left and root->right){
            return ans;
        }
        return max(ans,x);
    }
