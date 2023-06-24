class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds) {
        // base case
        if(ind < 0) {
            ans.push_back(ds);
            return;
        }
        
        // not pick the element 
        solve(ind - 1, nums, ans, ds);
        
        ds.push_back(nums[ind]);
        // pick the element
        solve(ind - 1, nums, ans, ds);
            
        // when recursion is reached the leaf node 
        // then start removing element from ds
        ds.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        int n = nums.size();
        solve(n - 1, nums, ans, ds);        
        
        
        return ans;
    }
};

// tc -> O(2^n)
// sc -> O(2 ^ n) + O(n)