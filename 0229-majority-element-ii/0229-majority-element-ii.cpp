class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans;
        
        map<int, int> mpp;
        
        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        
        for(int i = 0; i < n; i++) {
                
            if(ans.size() == 1 && ans[0] == nums[i]) continue;
            
            if(mpp[nums[i]] > n / 3) ans.push_back(nums[i]);
            
            if(ans.size() == 2) break;
        }
        
        return ans;
    }
};