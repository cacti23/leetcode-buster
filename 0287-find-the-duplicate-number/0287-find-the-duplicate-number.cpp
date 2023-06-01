class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // using sort 
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = -1;
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                ans = nums[i];
                break;
            }
        }
        
        return ans;
        
    }
};

// tc -> O(nlogn + n)
// sc -> O(1)