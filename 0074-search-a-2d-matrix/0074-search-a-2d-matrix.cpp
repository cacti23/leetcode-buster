class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // brute force soolution 
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // traverse the whole matrix 
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == target) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

// tc -> O(m*n)
// sc -> O(1)