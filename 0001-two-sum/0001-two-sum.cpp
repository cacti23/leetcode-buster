class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // using hashing
        int n = nums.size();
        
        vector<int> ans;
        
        map<int, int> mpp;
        // key difference and value index
        
        for(int i = 0; i < n; i++) {
            int diff = target - nums[i];
            
            if(mpp.find(diff) != mpp.end()) {
                ans.push_back(i);
                ans.push_back(mpp[diff]);
                break;
            }
            
            mpp[nums[i]] = i;
         }
        
        return ans;
    }
};