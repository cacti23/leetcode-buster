class Solution {
public:
    void reverse(vector<int>& arr, int start, int end) {
        while(start < end) {
            swap(arr[start++], arr[end--]);
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // step 1: transpose the matrix
        for(int i = 0; i < n; i++) {
            // j < i is really important here in order to transpose correctly 
            // in 1st row we want only one swap ie 1, 0
            // in 2nd row we want two swaps 2, 0 and 2, 1
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // step 2: reverse every row 
        for(int i = 0; i < n; i++) {
            reverse(matrix[i], 0, n - 1);
        }
        
        return;
    }
};