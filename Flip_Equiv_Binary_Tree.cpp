// https://leetcode.com/problems/flip-equivalent-binary-trees/description/
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
      if(root1==NULL){
        return root2==NULL;
      }   
      if(root2==NULL){
        return root1==NULL;
      }
      if(root1->val!=root2->val){
        return false;
      }
      return  (flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right))
      ||(flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left));
    }
};
