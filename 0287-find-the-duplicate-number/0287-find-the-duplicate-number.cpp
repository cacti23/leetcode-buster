class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // using linked list cycle method        
        // detect cycle 
        int slow = nums[0], fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        // cycle is there 
        fast = nums[0];
        
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    } 
};

// tc -> O(n)
// sc -> O(1)