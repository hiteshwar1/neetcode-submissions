class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents;
        vector<int> ranks;
        for(int i=0;i<n;i++){
            parents.push_back(i);
            ranks.push_back(1);
        }
        int res = n;
        for(int i=0;i<edges.size();i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            res -= Union(parents,ranks,n1,n2);
        }
        return res;
    }
    int findParent(vector<int>& parents, int n) {
        int res = n;
        while(res!=parents[res]){
            parents[res] = parents[parents[res]];
            res = parents[res];
        }
        return res;
    }
    int Union(vector<int> &parents,vector<int> &ranks,int n1,int n2){
        int p1 = findParent(parents,n1);
        int p2 = findParent(parents,n2);
        if(p1==p2) return 0;

        if(ranks[p1]>ranks[p2]){
            parents[p2] = p1;
            ranks[p1]+=ranks[p2];
        }
        else{
            parents[p1] = p2;
            ranks[p2]+=ranks[p1];
        }
        return 1;
    }
};
