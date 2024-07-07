// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description

 TreeNode* reverseOddLevels(TreeNode* root) {
         queue<TreeNode*>q;
         vector<int>values;
         int level=0;
         q.push(root);
         while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();q.pop();
                if(level%2==1){
                    curr->val=values[n-i-1];
                }
                if(curr->left){
                    q.push(curr->left);
                    temp.push_back(curr->left->val);
                }
                if(curr->right){
                    q.push(curr->right);
                    temp.push_back(curr->right->val);
                }

            }
            values=temp;level++;
         }
         return root;
    }
