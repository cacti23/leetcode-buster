class Solution {
public:
    void sortColors(vector<int>& nums) {
        // step 1: counting the occurence of 0, 1, and 2
        int a = 0, b = 0, c = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) a++;
            else if(nums[i] == 1) b++;
            else c++;
        }
        
        // step 2: populating the given input array 
        for(int i = 0; i < n; i++) {
            if(a > 0) {
                nums[i] = 0;
                a--;
            } else if (b > 0) {
                nums[i] = 1;
                b--;
            } else {
                nums[i] = 2;
            }
        }
        
        return;
    }
};