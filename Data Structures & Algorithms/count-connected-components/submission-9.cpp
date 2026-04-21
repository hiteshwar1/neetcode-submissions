class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> ranks(n,1);
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        for(int i=0;i<edges.size();i++){
            int x = edges[i][0];
            int y = edges[i][1];
            n -= findUnion(ranks,parent,x,y);
        }
        return n;
    }

    int findParent(vector<int> &parent,int x){
        int res = x;
        while(res!=parent[res]){
            parent[res] = parent[parent[res]];
            res = parent[res];
        }
        return res;
    }

    int findUnion(vector<int> &ranks,vector<int>& parent,int x,int y){
        int parentX = findParent(parent,x);
        int parentY = findParent(parent,y);

        if(parentX == parentY) return 0;

        if(ranks[parentX]>ranks[parentY]){
            ranks[parentX]+=ranks[parentY];
            parent[y] = parentX;
        }
        else{
            ranks[parentY]+=ranks[parentX];
            parent[x] = parentY;
        }

        return 1;

    }
};
