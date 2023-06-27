class Solution {
public:
    int search(vector<int>& nums, int target) {
        // use binary serach 
        int n = nums.size();
        
        int low = 0, high = n - 1;
        
        // obervation make is either left half is sorted or right half is sorted 
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target) {
                return mid;
            }
            // if left half is sorted 
            if(nums[low] <= nums[mid]) {
                // if elements exists between low and mid
                if(nums[low] <= target && nums[mid] >= target) {
                    high = mid - 1;
                } else {
                    // if the element does not exists in this half
                    low = mid + 1;
                }
            } else {
                // right half is sorted
                // if element exists between high and mid
                if(nums[mid] <= target && nums[high] >= target) {
                    low = mid + 1;
                } else {
                    // if the elements does not exists in this half
                    high = mid - 1;
                }
            }
           
    
        }
        
        
        return -1;
    }
};