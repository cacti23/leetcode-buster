class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // using frequency array 
        int n = nums.size();
        
        vector<int> freq(n, 0);
        
        int ans = -1;
        
        // populate freq 
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        
        // check for repeat in freq array
        for(int i = 1; i < n; i++) {
            if(freq[i] > 1) {
                ans = i;
            }
        }
        
        return ans;
    }
};

// tc -> O(n) + O(n)
// sc -> O(n)