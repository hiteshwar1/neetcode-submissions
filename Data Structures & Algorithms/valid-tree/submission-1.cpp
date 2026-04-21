class Solution {
public:
    bool cycleDfs(vector<int> adj[], int node, vector<bool>& vis, int parent) {
    vis[node] = true;
    for (auto i : adj[node]) {
        if (!vis[i]) {
            if (cycleDfs(adj, i, vis, node)) return true;
        }
        // If an adjacent node is visited and is not the parent, a cycle is found.
        else if (i != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(vector<int> adj[], int n) {
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (cycleDfs(adj, i, vis, -1)) return true;
        }
    }
    return false;
}

void dfs(vector<int> adj[], int node, vector<bool>& vis, int& cnt) {
    vis[node] = true;
    cnt++;
    for (auto i : adj[node]) {
        if (!vis[i]) {
            dfs(adj, i, vis, cnt);
        }
    }
}

bool isConnected(vector<int> adj[], int n) {
    vector<bool> vis(n, false);
    int cnt = 0;
    dfs(adj, 0, vis, cnt);
    return cnt == n;
}

bool validTree(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false; // A tree must have exactly n-1 edges
    
    vector<int> adj[n];
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // Check if the graph is connected
    bool connected = isConnected(adj, n);

    // Check if there is a cycle
    bool cyclic = isCycle(adj, n);

    return connected && !cyclic;
}


};
