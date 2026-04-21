class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(vector<int> adj[],int node,vector<bool>& vis){
        vis[node] = true;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(adj,i,vis);
            }
        }
    }
};
