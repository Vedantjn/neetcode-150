class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        if (matrix.empty()) return ans;

        int n = matrix.size();
        int m = matrix[0].size();

        int rowStart = 0;
        int rowEnd = n - 1;
        int colStart = 0;
        int colEnd = m - 1;

        while (rowStart <= rowEnd && colStart <= colEnd) {
            // Traverse Right
            for (int i = colStart; i <= colEnd; i++) {
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;

            // Traverse Down
            for (int i = rowStart; i <= rowEnd; i++) {
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;

            // Traverse Left (if still within bounds)
            if (rowStart <= rowEnd) {
                for (int i = colEnd; i >= colStart; i--) {
                    ans.push_back(matrix[rowEnd][i]);
                }
                rowEnd--;
            }

            // Traverse Up (if still within bounds)
            if (colStart <= colEnd) {
                for (int i = rowEnd; i >= rowStart; i--) {
                    ans.push_back(matrix[i][colStart]);
                }
                colStart++;
            }
        }

        return ans;
    }
};
