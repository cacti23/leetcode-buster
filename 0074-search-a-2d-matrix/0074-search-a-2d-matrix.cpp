class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // brute force soolution 
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        if(rows == 1) {
            for(int i = 0; i < cols; i++) {
                if(target == matrix[0][i]) return true;
            }
        }
        
        int rowToSearch = -1;
        
        // traverse the last column
        for(int i = 1; i < rows; i++) {
            int ele1 = matrix[i - 1][cols - 1]; // last element of previous row
            int ele2 = matrix[i][cols - 1]; // last element of current row
            // we know that ele1 is less than ele2
            /// write conditions
            
            if(target <= ele1) {
                if(target == ele1) return true;
                rowToSearch = i - 1;
                break;
            } else if(target > ele1 && target <= ele2) {
                if(target == ele2) return true;
                rowToSearch = i;
                break;
            } 
        }
        
        
        if(rowToSearch == -1) {
            return false;
        }
        
        
        // we have a row where we can find the element 
        for(int i = 0; i < cols; i++) {
            if(target == matrix[rowToSearch][i]) return true;
        }
        
        
        return false;
    }
};

// tc -> O(m*n)
// sc -> O(1)