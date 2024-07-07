 void populate(Node* root,Node*&prev){
        if(root==NULL){
            return;
        }
        populate(root->left,prev);
        if(prev==NULL){
            prev=root;
        }
        else{
            prev->next=root;
            prev=root;
        }
        populate(root->right,prev);
    }
    void populateNext(Node *root) {
        Node* prev=NULL;
        populate(root,prev);
    }
