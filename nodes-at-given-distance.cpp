// Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.

    void dfs(Node* node, Node* par) {
        if (node) {
            parent[node] = par;
            dfs(node->left, node);
            dfs(node->right, node);
        }
        else{return;}
    }

   Node* t1(Node*root,int target){
        if(root==NULL){
            return NULL;
        }
      
        Node* left_res = t1(root->left, target);
          if(root->data==target){
            return root;
        }
        Node* right_res = t1(root->right, target);
    
        if(left_res) return left_res;
        else return right_res;
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
       vector<int> ans;
        if(root==NULL){
            return ans;
        }
        dfs(root,NULL);
        Node* targetNode = t1(root,target);
        
        queue<Node*> q;
        q.push(targetNode);
        unordered_set<Node*> visited;
        
        while(!q.empty() && k>0){
          k--;
          int size = q.size();
          for(int i=0;i<size;i++){
                Node* temp = q.front();
                q.pop();
                visited.insert(temp);
                
                if(!visited.count(temp->left) && temp->left){
                    q.push(temp->left);
                }
                if(!visited.count(temp->right) && temp->right){
                    q.push(temp->right);
                }
                if(!visited.count(parent[temp]) && parent[temp]){
                    q.push(parent[temp]);
                }
          }
        }
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            ans.push_back(curr->data);
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
