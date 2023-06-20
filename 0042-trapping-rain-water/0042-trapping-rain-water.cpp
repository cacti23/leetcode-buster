class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        
        int prefix[n], suffix[n];
        
        // compute prefix array
        // to calculate prefix array start from the left
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], arr[i]);
        }
        
        // compute suffix array 
        // to calculate suffix array start from the right 
        suffix[n - 1] = arr[n - 1];
        
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], arr[i]);
        }
        
        int waterTrapped = 0;
        
        for(int i = 0; i < n; i++) {
            waterTrapped += (min(prefix[i], suffix[i]) - arr[i]);
        }
        
        return waterTrapped;
    }
};