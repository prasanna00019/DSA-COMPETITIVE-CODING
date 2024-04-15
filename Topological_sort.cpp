void dfs(int u, vector<int> adj[], vector<bool>& visited, stack<int>& finished) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, finished);
        }
    }
    finished.push(u); // Push the vertex onto the stack when its DFS is complete
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    stack<int> finished; // Stack to store vertices in descending order of finish times

    // Perform DFS on all vertices
    for (int u = 0; u < V; ++u) {
        if (!visited[u]) {
            dfs(u, adj, visited, finished);
        }
    }

    // Extract the result from the stack
    vector<int> result;
    while (!finished.empty()) {
        result.push_back(finished.top());
        finished.pop();
    }
    return result;
}
}
