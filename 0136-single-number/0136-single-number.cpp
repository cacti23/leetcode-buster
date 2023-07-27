class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // using hashing
        unordered_map<int, int> umap;
        
        int n = nums.size();
        
        // populate the map
        for(int i = 0; i < n; i++) {
            umap[nums[i]]++;
        }
        
        // check which elements is only present once 
        for(auto it: umap) {
            if(it.second == 1) {
                return it.first;
            }
        }
        
        return -1;
    }
};

// tc -> O(n) + O(n)
// sc -> O(n)