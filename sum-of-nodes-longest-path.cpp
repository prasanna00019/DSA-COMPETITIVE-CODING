// Sum of nodes on the longest path from root to leaf node
// Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. 
// If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.

void helper(Node* root,int h,int s,int &ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL and root->right==NULL){
            s+=root->data;
            if(h>mh){
                ans=s;mh=h;
            }
            else if(h==mh){
                ans=max(ans,s);
            }
        }
        s+=root->data;
        helper(root->left,h+1,s,ans);helper(root->right,h+1,s,ans);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {    
          helper(root,0,0,ans);
          return ans;
    }
