// https://www.geeksforgeeks.org/problems/burning-tree/1
void buildGraph(Node* root, Node* parent, unordered_map<int, vector<int>>& mp) {
    if (!root) {
        return;
    }
    if (mp.find(root->data) == mp.end()) {
        mp[root->data] = {};
    }
    if (parent) {
        mp[root->data].push_back(parent->data);
    }
    if (root->left) {
        mp[root->data].push_back(root->left->data);
        buildGraph(root->left, root, mp);
    }
    if (root->right) {
        mp[root->data].push_back(root->right->data);
        buildGraph(root->right, root, mp);
    }
}

int minTime(Node* root, int target) {
    unordered_map<int, vector<int>> mp;
    buildGraph(root, NULL, mp);
    queue<int> q;
    q.push(target);
    unordered_set<int> visited;
    visited.insert(target); // Mark the target node as visited initially
    int time = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int node = q.front();
            q.pop();
            for (int neighbor : mp[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        if (!q.empty()) {
            time++;
        }
    }
    return time;
}
