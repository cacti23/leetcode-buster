class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // using binary search 
        int rows = matrix.size();
        int cols = matrix[0].size();
        int lo = 0;
        int hi = (rows* cols) - 1;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            // update row and col 
            if(matrix[mid / cols][mid % cols] == target) return true;
            
            // search right side
            else if(matrix[mid / cols][mid % cols] < target) {
                lo = mid + 1;
            }
            
            // search left side 
            else {
                hi = mid - 1;
            }
        }
        
        return false;
    }
};