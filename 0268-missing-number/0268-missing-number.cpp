class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // using xor
        int n = nums.size();
        int xr = 0;
        
        // xor of all the numbers from 0 to n
        for(int i = 0; i <= n; i++) {
            xr ^= i;
        }
        
        // xor of all the numbers in the array 
        for(int i = 0; i < n; i++) {
            xr ^= nums[i];
        }
        
        return xr;
    }
};

// tc -> O(n) + O(n)
// sc -> O(1)