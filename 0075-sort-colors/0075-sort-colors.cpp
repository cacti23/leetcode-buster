class Solution {
public:
    void sortColors(vector<int>& nums) {
        // step 1: count the 0 1 and 2
        int arr[] = {0, 0, 0};
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                arr[0]++;
            } else if(nums[i] == 1) {
                arr[1]++;
            } else {
                arr[2]++;
            }
        }
        
        // step 2: populate the nums array 
        for(int i = 0; i < n; i++) {
            if(arr[0] > 0) {
                nums[i] = 0;
                arr[0]--;
            } else if(arr[1] > 0) {
                nums[i] = 1; 
                arr[1]--;
            } else {
                nums[i] = 2;
            }
        }
        
    }
};

// tc -> O(n)
// sc -> O(1)