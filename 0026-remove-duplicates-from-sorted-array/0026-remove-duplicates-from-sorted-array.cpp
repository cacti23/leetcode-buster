class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // use hashset
        set<int> hset;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            hset.insert(nums[i]);
        }
        
        int k = hset.size();
        int j = 0;
        
        for(auto x: hset) {
            nums[j++] = x;
        }
        
        return k;
    }
};

// tc -> O(n*logn) + O(n)
// sc -> O(n)