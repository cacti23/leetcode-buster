class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // using freq array 
        int n = nums.size();
        
        vector<int> freq(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        
        // now check the freq array to find the missing element 
        for(int i = 0; i <= n; i++) {
            if(freq[i] == 0) {
                return i;
            }
        }
        
        return -1;
        
    }
};

// tc -> O(n) + O(n)
// sc -> O(n)