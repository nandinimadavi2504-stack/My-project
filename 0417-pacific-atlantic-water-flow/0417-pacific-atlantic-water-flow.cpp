class Solution {
public:
    int m,n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();          // ✅ Now it's valid
        n = heights[0].size();       // ✅ Access first row safely
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        
        // Start DFS from Pacific (top row + left column)
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);          // left column
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);          // top row
        }
        
        // Start DFS from Atlantic (bottom row + right column)
        for (int i = 0; i < m; i++) {
            dfs(heights, atlantic, i, n - 1);     // right column
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, atlantic, m - 1, j);     // bottom row
        }
        
        // Collect cells reachable to both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int r, int c) {
        visited[r][c] = 1;
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto &dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            // Check bounds and non-visited and flow condition
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, visited, nr, nc);
            }
        }

        
    }
};