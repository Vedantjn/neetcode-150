class Solution {
public:
    int dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int area = 1;  // Initial area for the current cell

        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int neighbourRow = row + delRow[i];
            int neighbourCol = col + delCol[i];

            if (neighbourRow >= 0 && neighbourRow < n && neighbourCol >= 0 && neighbourCol < m && 
                !visited[neighbourRow][neighbourCol] && grid[neighbourRow][neighbourCol] == '1') {
                area += dfs(neighbourRow, neighbourCol, grid, visited);
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    int area = dfs(i, j, grid, visited);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
