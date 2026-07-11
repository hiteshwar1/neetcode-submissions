class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
        }
        vector<int> indegree(numCourses, 0);
        for (auto i : adj) {
            for (auto j : i) {
                indegree[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto i : adj[node]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        return cnt == numCourses;
    }
};
