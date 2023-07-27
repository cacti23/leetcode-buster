class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        // find the first zero
        int j = -1;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                j = i;
                break;
            }
        }
        
        // if there is not zero present
        if(j == -1) return;
        
        // find the first zero we can traverse the whole array 
        // if you find the non zero element swap with the element of index j
        for(int i = j + 1; i < n; i++) {
            if(nums[i] != 0) {
                swap(nums[j], nums[i]);
                j++;
            }
        }
        
        return;
    }
};

// tc -> O(n)
// sc -> O(1)