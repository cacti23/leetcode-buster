class Solution {
public:
    void reverse(vector<int> &nums, int start, int end) {
        while(start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            
            start++;
            end--;
        }
        
        return;
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // if k is greater than n perform the modulo operation
        if(k >= n) {
            k %= n;
        }
        
        // now k will be always less than n
        
        // reverse the whole array once
        reverse(nums, 0, n - 1);
        
        // now we need to reverse the left and right part separately 
        // left part 
        reverse(nums, 0, k - 1);
        
        // right part
        reverse(nums, k, n - 1);
        
        return;
    }
};

// tc -> O(n)
// sc -> O(1)