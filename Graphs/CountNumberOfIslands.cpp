class Solution {
public:

    void dfs(int row, int col, vector<vector<char>>&grid, vector<vector<int>>&visited){
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int neighbourRow = row + delRow[i];
            int neighbourCol = col + delCol[i];

            if(neighbourRow >= 0 && neighbourRow < n && neighbourCol >= 0 && neighbourCol < m && !visited[neighbourRow][neighbourCol] && grid[neighbourRow][neighbourCol] == '1'){
                dfs(neighbourRow, neighbourCol, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return count;
    }
};





class Solution {
public:
    void rec(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        rec(grid, i + 1, j, m, n);
        rec(grid, i, j + 1, m, n);
        rec(grid, i - 1, j, m, n);
        rec(grid, i, j - 1, m, n);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    rec(grid, i, j, m, n);
                }
            }
        }
        return res;
    }
};