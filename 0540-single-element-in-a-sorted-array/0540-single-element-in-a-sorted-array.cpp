class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // using binary search 
        int n = nums.size();
        
        if(n == 1) return nums[0];
        
        // n will always be odd
        
        int low = 0, high = n - 1;
        
        // keping single element as reference 
        // left half -> 1st instance -> even Index and 2nd instance -> odd index
        // right half -> 1st instance -> Odd Index and 2nd instance -> even index
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            // check if mid is even
            if(mid % 2 == 0) {
                // determine which half we are present in
                if(nums[mid] != nums[mid + 1]) {
                    // second instance 
                    high = mid - 1;
                } else {
                    // first instance 
                    low = mid + 1;
                }
            } else {
                // mid is odd
                if(nums[mid] != nums[mid + 1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
                
            }
        }
        
        return nums[low];
    }
};