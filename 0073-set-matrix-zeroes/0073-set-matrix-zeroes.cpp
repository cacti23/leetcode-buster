class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        
        vector<int> rowArr(rowSize, 0);
        vector<int> colArr(colSize, 0); 

        for(int row = 0; row < rowSize; row++) {
            for(int col = 0; col < colSize; col++) {
                if(matrix[row][col] == 0) {
                    rowArr[row] = 1;
                    colArr[col] = 1;
                }
            }
        }
        
        for(int row = 0; row < rowSize; row++) {
            for(int col = 0; col < colSize; col++) {
                if(rowArr[row] == 1 || colArr[col] == 1) {
                    matrix[row][col] = 0;
                }
            }
        }
        
        return; 
    }
};