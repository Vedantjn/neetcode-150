class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = m*n - 1;

        while(low <= high){
            int mid = (low+high) >> 1;

            if(matrix[mid/m][mid%m] < target){
                low = mid+1;
            }
            else if(matrix[mid/m][mid%m] > target){
                high = mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};


// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(matrix[i][j] == target){
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };