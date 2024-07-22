class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return;
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Initialize the queue with all the treasure chests' positions
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (const auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                // Check if the new position is within the bounds and is a land cell (INF)
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 2147483647) {
                    // Update the distance to the nearest treasure chest
                    grid[newRow][newCol] = grid[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
};
