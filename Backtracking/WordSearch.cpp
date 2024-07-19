class Solution {
private:
    bool check(int i, int j, int k, int& len, int& n, int& m, vector<vector<char>>& board, string word) {
        if (k == len)
            return true;
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        if (board[i][j] != word[k])
            return false;
        
        // If the character at (i, j) matches the current character in the word, proceed to the next character
        k++;
        
        // Store the current character at (i, j) and mark it as visited by changing its value to '1'
        char letter = board[i][j];
        board[i][j] = '1';
        
        // Recursively check the neighboring cells for the next character in the word
        bool flag = check(i + 1, j, k, len, n, m, board, word) ||   // Down
                    check(i - 1, j, k, len, n, m, board, word) ||   // Up
                    check(i, j + 1, k, len, n, m, board, word) ||   // Right
                    check(i, j - 1, k, len, n, m, board, word);    // Left
        
        // Restore the original character at (i, j)
        board[i][j] = letter;
        
        return flag;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.length();
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check(i, j, 0, len, n, m, board, word))
                    return true;
            }
        }
        return false;
    }
};




class Solution {
public:
    bool find(vector<vector<char>>& board, vector<vector<int>>& visited, string& word, vector<pair<int,int>>& dirc, int row, int col, int idx) {
        
        if (idx == word.size()) return true; // Successfully found the word
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col] || board[row][col] != word[idx]) {
            return false; // Out of bounds or already visited or character doesn't match
        }

        visited[row][col] = 1; // Mark this cell as visited

        for (auto& d : dirc) { // Try all four directions
            int newRow = row + d.first;
            int newCol = col + d.second;
            if (find(board, visited, word, dirc, newRow, newCol, idx + 1)) {
                return true; // Found the word in one of the directions
            }
        }
        visited[row][col] = 0; // Backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0)); // To keep track of visited cells
        vector<pair<int, int>> dirc = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}; // Four possible directions

        for (int i = 0; i < n; ++i) { // Try to start from every cell
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0] && find(board, visited, word, dirc, i, j, 0)) {
                    return true; // Found the word
                }
            }
        }
        return false; // Word not found in the grid
    }
};