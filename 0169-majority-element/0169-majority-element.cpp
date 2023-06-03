class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // if we sort the array mid will the the marjority element always 
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int low = 0, high = n - 1;
        
        int mid = low + (high - low) / 2;
        
        return nums[mid];
    }
};