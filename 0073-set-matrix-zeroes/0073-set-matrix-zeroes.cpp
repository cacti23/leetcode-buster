class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowSize = matrix.size(); // number of rows
        int colSize = matrix[0].size(); // number of columns
        
        int col0 = 1;
        
        for(int row = 0; row < rowSize; row++) {
            for(int col = 0; col < colSize; col++) {
                if(matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    if(col != 0) {
                        matrix[0][col] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }
        
        // start traversal from (1, 1) to (n - 1, m - 1)
        for(int row = 1; row < rowSize; row++) {
            for(int col = 1; col < colSize; col++) {
                if(matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }
        
        // process the col array -> (0,0)
        if(matrix[0][0] == 0) {
            for(int col = 1; col < colSize; col++) {
                matrix[0][col] = 0;
            }
        }
        
        // process the row array -> col0
        if(col0 == 0) {
            for(int row = 0; row < rowSize; row++) {
                matrix[row][0] = 0;
            }
        }
        
        return; 
    }
};