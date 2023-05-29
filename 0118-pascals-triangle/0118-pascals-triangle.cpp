class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int row = 1; row <= numRows; row++) {
            vector<int> temp;
            temp.push_back(1);
            
            int res = 1;
            
            for(int col = 1; col < row; col++) {
                res = res * (row - col);
                res = res / col;
                
                temp.push_back(res);
            }
            
            ans.push_back(temp);
        }
        
        return ans;  
    }
};