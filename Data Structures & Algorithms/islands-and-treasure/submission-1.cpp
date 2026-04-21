class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int val = q.front().second;
            grid[x][y] = val;
            q.pop();
            int dx[] = {-1,0,1,0};
            int dy[] = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != -1 && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    q.push({{nx,ny},val+1});
                }
            }
        }
    }
};
