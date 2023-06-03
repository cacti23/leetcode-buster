class Solution {
public:
    int majorityElement(vector<int>& nums) {        
        int n = nums.size();
        
        map<int, int> mpp;
        
        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        
        for(int i = 0; i < n; i++) {
            if(mpp[nums[i]] > n / 2) return nums[i];
        }
        
        return -1;
    }
};