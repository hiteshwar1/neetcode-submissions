class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        for (auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
        }

        queue<int> q;
        vector<int> indegree(n, 0);
        for (auto i : adj) {
            for (auto j : i) {
                indegree[j]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        int res = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res++;
            for (auto i : adj[node]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        return res == n;
    }
};
