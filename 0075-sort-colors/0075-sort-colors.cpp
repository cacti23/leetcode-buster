class Solution {
public:
    void sortColors(vector<int>& nums) {
        // store the occurence of red, white and blue objects 
        int r = 0, w = 0, b = 0;
        int n = nums.size();
        // int count[3] = {0};
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) r++;
            else if(nums[i] == 1) w++;
            else b++;
        }
        
        // populate the input array it self 
        for(int i = 0; i < n; i++) {
            if(r > 0) {
                nums[i] = 0;
                r--;
            } else if(w > 0) {
                nums[i] = 1;
                w--;
            } else if(b > 0) {
                nums[i] = 2;
                b--;
            }
        }
        
        return;
    }
};

// tc => O(n) + O(n)
// sc -> O(1)