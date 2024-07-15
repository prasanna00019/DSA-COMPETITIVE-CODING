// https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2024-07-15
 TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int>indeg;
        unordered_map<int,TreeNode*>valueNodeMp;
        for(auto x:descriptions){
            int parent=x[0];int child=x[1];
            bool leftchild=x[2];
            if(indeg.find(parent)==indeg.end()){
                indeg[parent]=0;
            }
            indeg[child]--;
            if(valueNodeMp.find(parent)==valueNodeMp.end()){
                valueNodeMp[parent]=new TreeNode(parent);
            }
            if(valueNodeMp.find(child)==valueNodeMp.end()){
                valueNodeMp[child]=new TreeNode(child);
            }
            if(leftchild){
                valueNodeMp[parent]->left=valueNodeMp[child];
            }
            else{
               valueNodeMp[parent]->right=valueNodeMp[child];
            }
        }
        for(auto it:indeg){
            if(it.second==0){
                return valueNodeMp[it.first];
            }
        }
        return NULL;
    }
