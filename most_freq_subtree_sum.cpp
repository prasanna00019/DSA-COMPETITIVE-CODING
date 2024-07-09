// https://leetcode.com/problems/most-frequent-subtree-sum/
class Solution {
public:
    int sum_node(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return root->val+sum_node(root->left)+sum_node(root->right);
    }
    void inorder(TreeNode* root,unordered_map<int,int>&mp,int &c){
        if(root==NULL){
            return;
        }
        else{
            inorder(root->left,mp,c);
            int s=sum_node(root);
            mp[s]++;c++;
            inorder(root->right,mp,c);
        }
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int>result;
    int c=0;int maxi=INT_MIN;
    int res=0;
    unordered_map<int,int>mp;
    inorder(root,mp,c);
    for(auto x:mp){
       res=max(res,x.second);
    }
    if(mp.size()==c){
        for(auto x:mp){
            result.push_back(x.first);
        }
    }
    else{
        for(auto x:mp){
            if(x.second==res){
                result.push_back(x.first);
            }
        }
    }
   return result;
    }
};
