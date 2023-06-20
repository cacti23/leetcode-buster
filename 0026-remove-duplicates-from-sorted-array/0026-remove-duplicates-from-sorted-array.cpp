class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // use two pointers approach
        int n = nums.size();
        
        int i = 0, j = 1;
        
        while(j < n) {
            // if the elements at i & j are same
            if(nums[i] == nums[j]) {
                j++;
            } else {
                i++;
                // swap the elements
                swap(nums[i], nums[j]);
                j++;
            }
        }
        
        // when this loop is completed from 0 to i index will represent the unique elements
        return i + 1;
        
    }
};