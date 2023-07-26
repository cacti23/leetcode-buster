class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // if k is greater than n then we have to do modulo
        if(k >= n) {
            k %= n;
        }
        
        // now k will be less than n
        vector<int> temp(n, 0);
        int idx = 0;
        
        // there will be a index that divides the given array 
        // later part will come first in the answer
        int ind = n - k;
        
        // now copy the later part into temp array
        for(int i = ind; i < n; i++) {
            temp[idx++] = nums[i];
        }
        
        // now copy the first part into temp arry 
        for(int i = 0; i < ind; i++) {
            temp[idx++] = nums[i];
        }
        
        // temp array is the answer so copy it back to nums array 
        for(int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
        
        return; 
    }
};

// tc -> O(n) + O(n) + O(n)
// sc -> O(n)