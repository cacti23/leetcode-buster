class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        // step 1: declare pointers 
        int i = n - 1, j = m - 1, k = n + m - 1;
        
        // step 2: now start from the end and insert elements into num1 because the size of nums 1 is n + m
        while(i >= 0 && j >= 0 && k >= 0) {
            if(nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        // the above while loop get over because either of i or j becoming negative when j becomes neasgtive then we dont have to do anything because all the elements from j side is inserted into nums 1 but if i becomes neagtaive then we need to process the remaining j elements 
        // step 2: process the elements for nums2
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
        
        return;
    }
};

// tc -> O(n + m)
// sc -> O(1)