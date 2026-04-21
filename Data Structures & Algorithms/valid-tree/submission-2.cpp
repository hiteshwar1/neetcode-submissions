class Solution {
public:
    bool hasCycle(vector<int> adj[],int n){
        vector<int> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfsCycle(adj,vis,i,-1)) return true;
            }
        }
        return false;
    }
    
    bool dfsCycle(vector<int> adj[],vector<int>& vis,int node,int parent){
        vis[node] = true;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfsCycle(adj,vis,i,node)) return true;
            }
            else if(i!=parent){
                return true;
            }
        }
        return false;
    }

    bool isConnected(vector<int> adj[],int n){
        vector<int> vis(n,false);
        dfsConnected(adj,vis,0);
        for(auto i:vis){
            if(i==0) return false;
        }
        return true;
    }

    void dfsConnected(vector<int> adj[], vector<int>& vis, int node){
        vis[node] = 1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfsConnected(adj,vis,i);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        return isConnected(adj,n) && !hasCycle(adj,n);
    }
};
