class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 1) return n;
        
        // sort the array 
        sort(nums.begin(), nums.end());
        
        // traverse the array 
        int ans = 0;
        int tempCnt = 0;
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] + 1 == nums[i + 1]) {
                tempCnt++;
            } else if(nums[i] == nums[i + 1]) {
                continue;
            } 
            else {
                tempCnt = 0;
            }
            
            ans = max(tempCnt, ans);
        }
        
        return ans + 1;
        
    }
};