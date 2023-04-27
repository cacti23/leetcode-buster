class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // element and index
        unordered_map<int, int> mpp;
        vector<int> ans(2);

        for(int i = 0; i < n; i++) {
            if(mpp.find(target - nums[i]) != mpp.end()) {
                // lesser index
                ans[0] = mpp[target - nums[i]];
                // greater index
                ans[1] = i;
                break;
            }

            mpp[nums[i]] = i;
        }

        return ans;
    }
};

// tc -> O(n)
// sc -> O(n)