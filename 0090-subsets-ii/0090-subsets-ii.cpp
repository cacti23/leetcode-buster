class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds) {
        ans.push_back(ds);
        
        // skip all the duplicate element 
        for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            
            ds.push_back(nums[i]);
            // we only call solve for next unique element;
            
            solve(i + 1, nums, ans, ds);

            // when recursion is reached the leaf node 
            // then start removing element from ds
            ds.pop_back();
         }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        // this is done to make sure we find duplicate easy
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        solve(0, nums, ans, ds);
        
        return ans;
    }
};

// tc -> O(2^n) (can be less than 2^n)
// sc -> O(n) + O(2^n) (if we include space complexity of answer array)