class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // use two pointer
        int n = nums.size();
        
        if(n == 1) return 1;
        
        int i = 0;
        for(int j = 1; j < n; j++) {
            // if i and j are not equal 
            // increment i and swap with j
            if(nums[i] != nums[j]) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        
        // need to return the number of unique elements hence incremented i with one
        return i + 1;
    }
};

// tc -> O(n)
// sc -> O(n)