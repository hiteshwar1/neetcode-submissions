class Solution {
public:
    bool isSafe(vector<int> adj[],int parent,int node,vector<bool>& vis){
        vis[node] = true;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(isSafe(adj,node,i,vis)) return true;
            }
            else if(i!=parent) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);
        //check for cycle
        if(isSafe(adj,-1,0,vis)) return false;
        //check for disconnect
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
