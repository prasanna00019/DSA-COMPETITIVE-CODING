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
