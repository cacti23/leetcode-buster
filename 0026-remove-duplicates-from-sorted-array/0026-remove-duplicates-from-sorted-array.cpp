class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // use ordered set 
        set <int> oset;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            oset.insert(nums[i]);
        }
        
        // here k will be the answer 
        // which indicates the number of unique elements
        int k = oset.size();
        
        // now copy unique elements to the input array
        int i = 0;
        for(auto it = oset.begin(); it != oset.end(); it++) {
            nums[i++] = *it;
        }
        
        return k;
        
    }
};

// tc -> O(n * logn) + O(n) -> O(n * logn)
// sc -> O(m) , where m is the number of unique elements