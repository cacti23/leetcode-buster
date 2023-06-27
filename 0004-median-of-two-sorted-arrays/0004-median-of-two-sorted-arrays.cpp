class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> arr(n + m);
        
        // use merge portion of merge sort
        // for tracking nums1, nums2 and arr
        int i = 0, j = 0, k = 0;
        
        while(i < n && j < m) {
            if(nums1[i] <= nums2[j]) {
                arr[k++] = nums1[i++];
            } else {
                arr[k++] = nums2[j++];
            }
        }
        
        while(i < n) {
            arr[k++] = nums1[i++];
        }
        
        while(j < m) {
            arr[k++] = nums2[j++];
        }
        
        double ans = 0;
        int temp = (n + m) / 2;
        // if the median
        if((n + m) % 2 == 0) {
            ans = (arr[temp] + arr[temp - 1]) / 2.0;
            
            return ans;
        } 
        
        return arr[temp];
        
        
    }
};

// tc -> O(n + m)
// sc -> O(n + m)