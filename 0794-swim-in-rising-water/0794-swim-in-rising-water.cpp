class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Min-heap: {elevation, x, y}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while (!pq.empty()) {
            auto [elev, x, y] = pq.top(); pq.pop();
            
            // If reached bottom-right
            if (x == n-1 && y == n-1) return elev;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({max(elev, grid[nx][ny]), nx, ny});
                }
            }
        }
        
        return -1; // Never reached
    }
};
