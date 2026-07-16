class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        for (auto i : adj) {
            for (auto j : i) {
                indegree[j]++;
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
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
        return res == numCourses;
    }
};
