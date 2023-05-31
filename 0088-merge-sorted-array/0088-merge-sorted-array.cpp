class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        // step 1: declare two pointers 
        int i = n - 1, j = 0;
        
        // step 2: start from end of nums1 and starting of num2 
        while(i >= 0 && j < m) {
            if(nums1[i] >= nums2[j]) {
                swap(nums1[i], nums2[j]);
                i--, j++;
            } else {
                break;
            }
        }
        
        // the time complexity of this loop will be O(min(n, m))
        // after this loop is completed nums1 will have all elements smaller than elements of nums2 
        // initially it was 1 3 5 7 and 0 2 6 8 9
        // after loop it will be 1 3 0 2 and 7 5 6 8 9 
        
        
        // step 3: sort each array 
        sort(nums1.begin(), nums1.end() - m); // tc -> O(nlogn)
        sort(nums2.begin(), nums2.end()); // tc -> O(mlogm)
        
        // step 4: copy elements of nums 2 to the end of nums1
        for(i = n, j = 0; i < n + m && j < m; i++,j++) {
            nums1[i] = nums2[j];
        }
        
        return;
    }
};

// tc -> O(min(n, m)) + O(nlogn) + O(nlogm)
// sc -> O(1)