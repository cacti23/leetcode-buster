class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        // step 1: declare a new array with size m + n
        vector<int> ans;
    
        
        // step 2: start a loop and insert elements into ans array 
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        
        // step 3: check for nums 1
        while(i < n) {
            ans.push_back(nums1[i]);
            i++;
        }
        
        // step 4: check for nums 2
        while(j < m) {
            ans.push_back(nums2[j]);
            j++;
        }
        
        // step 5: copy answer to the nums 1 array 
        for(int k = 0; k < (n + m); k++) {
            nums1[k] = ans[k];
        }
        
        return;
    }
};