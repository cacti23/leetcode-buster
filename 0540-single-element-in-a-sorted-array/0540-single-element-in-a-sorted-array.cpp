class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // using xor operator
        int n = nums.size();
        
        int ele = 0;
        
        for(int i = 0; i < n; i++) {
            ele = ele ^ nums[i];
        }
        
        return ele;
    }
};

// tc -> O(n)
// sc -> O(1)