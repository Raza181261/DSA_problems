class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        auto cmp = [&](pair<int,int>& a, pair<int,int>& b){ return heightMap[a.first][a.second] > heightMap[b.first][b.second]; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        // Push all boundary cells into pq
        for (int i = 0; i < m; ++i) {
            pq.push({i,0}); pq.push({i,n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; ++j) {
            pq.push({0,j}); pq.push({m-1,j});
            visited[0][j] = visited[m-1][j] = true;
        }

        int res = 0;
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        while (!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            int x = cell.first, y = cell.second;

            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                res += max(0, heightMap[x][y] - heightMap[nx][ny]);
                heightMap[nx][ny] = max(heightMap[nx][ny], heightMap[x][y]);
                pq.push({nx, ny});
            }
        }

        return res;
    }
};
