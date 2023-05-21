class Solution {
public:
    void sortColors(vector<int>& nums) {
        // step 1: setup pointers
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        
        // step 2: traver the array 
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++; 
                mid++;
            } else if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            } else if(nums[mid] == 1) {
                mid++;
            }
        }
    }
};

// Dutch national flag problem -> think of it where ever we need to sort three things
// The array is traversed only one time

// tc -> O(n)
// sc -> O(1)