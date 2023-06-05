class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // using two for loops 
        int n = nums.size();
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && (nums[i] + nums[j]) == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    cout << "heu" << endl;
                    break;
                }
            }
            
            if(ans.size() == 2) break;
        }
        
        return ans;
    }
};