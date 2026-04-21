class Solution {
public:
    void dfs(vector<int> adj[],int node,vector<int>& vis){
        vis[node] = true;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(adj,i,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,i,vis);
            }
        }
        return cnt;
    }
};
