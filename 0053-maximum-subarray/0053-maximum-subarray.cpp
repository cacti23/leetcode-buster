class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            // add new elements to the sum
            sum += nums[i];
            
            // update maxi
            maxi = max(maxi, sum);
            
            // if sum is negative then it will not help to find the subarray with maximum sum 
            if(sum < 0) sum = 0;
        }
        
        return maxi;
    }
};

// tc -> O(n)
// sc -> O(1)
