class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
        
        return;
    }
    
    void nextPermutation(vector<int>& nums) {
        // step 1: find breakpoint -> arr[i] < arr[i + 1]
        int n = nums.size();
        int bp = -1;
        
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                bp = i;
                break;
            }
        }
        
        // step 2: if bp exists or not 
        if(bp == -1) {
            reverse(nums, 0, n - 1);
            return;
        }
        
        // step 3: find the element greater than bp
        int x = -1;
        
        for(int i = n - 1; i > bp; i--) {
            if(nums[i] > nums[bp]) {
                x = i;
                break;
            }
        }
        
        // step 4: swap the bp and x
        swap(nums[bp], nums[x]);
        
        // step 5: reverse the right half of bp
        reverse(nums, bp + 1, n - 1);
        
        return;
    }
};