problem-statement
Sum of nodes on the longest path from root to leaf node
Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. 
If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.

solution code C++
int ans=0,mh=0;
    void solve(Node* root, int h, int s){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            s+=root->data;
            if(h>mh){
                ans=s;
                mh=h;
            }
            else if(h==mh){
                ans=max(ans, s);
            }
       //     return ;
        }
        
        s+=root->data;
        solve(root->left, h+1, s);
        solve(root->right, h+1, s);
        
     //   return;
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
          solve(root, 0, 0);
          return ans;
    }
