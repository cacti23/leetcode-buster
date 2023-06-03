class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // if we sort the array mid will the the marjority element always 
        sort(nums.begin(), nums.end());
        
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