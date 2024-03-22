/*
Diameter of a Binary Tree

The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. 
The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded 
(note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 
*/
 int diameter(Node* root) {
        // Your code here
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
    private:
    int height(Node* root,int &diameter){
        if(root==NULL){ return 0;}
        int lh=height(root->left,diameter);
        int rh=height(root->right,diameter);
        diameter=max(diameter,1+lh+rh);
        return 1+max(lh,rh);
        
    }
