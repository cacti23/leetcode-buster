class Solution {
public:
    void sortColors(vector<int>& nums) {
        // dutch national flag problem 
        // where we need to sort three things think abou this problem 
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        
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

// tc -> O(n)
// sc -> O(1)