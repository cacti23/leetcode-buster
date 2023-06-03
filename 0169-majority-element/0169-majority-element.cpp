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
        
        // you can verify also becuase in some other question it wil be like majority element may exists
        
        int cntVerify = 0;
        for(int i = 0; i < n; i++) {
            if(element == nums[i]) {
                cntVerify++;
            }
        }
        
        if(cntVerify > n / 2) return element;
        
        return -1;
    }
};