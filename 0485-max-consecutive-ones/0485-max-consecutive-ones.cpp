class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        
        int maxi = 0;
        int tempMaxi = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                tempMaxi++;
            } else {
                tempMaxi = 0;
            }
            
            maxi = max(maxi, tempMaxi);
        }
        
        return maxi;
    }
};