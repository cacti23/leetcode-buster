class Solution {
public:
    int majorityElement(vector<int>& nums) {        
        int n = nums.size();
        
        if(n <= 2) return nums[0];
        
        int cnt = 0, element = nums[0];
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == element) cnt++;
            else cnt--;
            
            if(cnt == 0) {
                cnt = 1;
                element = nums[i];
            }
        }
        
        return element;
    }
};