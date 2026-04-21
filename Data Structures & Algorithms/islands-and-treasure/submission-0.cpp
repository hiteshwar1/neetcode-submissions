class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else if(grid[i][j]==-1){
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first.first, y = q.front().first.second, dist = q.front().second;
            if(grid[x][y]==INT_MAX) {
                grid[x][y] = dist;
            }
            q.pop();
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int newX = x+dx[i], newY = y+dy[i];
                if(newX>=0&&newX<n&&newY>=0&&newY<m&&!vis[newX][newY]){
                    vis[newX][newY] = 1;
                    q.push({{newX,newY},dist+1});
                }
            }
        }
    }
};
