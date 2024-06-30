// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

  stack<TreeNode*>left;
   stack<TreeNode*>right;
    void push_left(TreeNode* root){
        while(root!=NULL){
            left.push(root);
            root=root->left;
        }
    }
    void push_right(TreeNode* root){
        while(root!=NULL){
            right.push(root);
            root=root->right;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        push_right(root);
        push_left(root);
        while(!left.empty() || ! right.empty()){
            TreeNode* a=left.top();
            TreeNode* b=right.top();
            if(a==b){
                return false;
            }
            int sum=a->val+b->val;
            if(sum==k){return true;}
            else if(sum<k){
                left.pop();
                push_left(a->right);
            }
            else{
                right.pop();
                push_right(b->left);
            }
        }
        return false;
    }
