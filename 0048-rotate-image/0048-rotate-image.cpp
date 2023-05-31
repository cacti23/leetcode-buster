class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // step 1: create a new matrix with n x n dimensions
        vector<vector<int>> newMatrix(n, vector<int>(n, 0));
        
        // step 2: copy the value from given matrix to new matrix 
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                newMatrix[row][col] = matrix[row][col];
            }
        }
        
        // step 3: copy 1st row of new of new matrix into last column to given matrix and so on
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[j][n - (i + 1)] = newMatrix[i][j];
            }
        }
        
        return;
    }
};