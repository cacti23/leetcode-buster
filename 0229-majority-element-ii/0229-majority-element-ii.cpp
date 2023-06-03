class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            
            if(ans.size() == 1 && ans[0] == nums[i]) continue;
            
            for(int j = 0; j < n; j++) {
                if(nums[i] == nums[j]) cnt++;
            }
            
            if(cnt > n / 3) {
                if(ans.size() == 2) break;
                
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};