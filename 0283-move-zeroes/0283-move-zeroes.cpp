class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // use temp array
        int n = nums.size();
        
        vector<int> temp(n, 0);
        int k = 0;
        
        // copy non zero element to temp array 
        for(int i = 0; i< n; i++) {
            if(nums[i] != 0) {
                temp[k++] = nums[i];
            }
        }
        
        // now copy back the elements to nums array 
        for(int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
        
        return;
    }
};

// tc -> O(n) + O(n)
// sc -> O(n)