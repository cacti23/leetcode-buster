class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // we need to apply binary search for array with smaller lenght
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        
        int n = nums1.size();
        int m = nums2.size();
        
        // we gonna apply binary serach low and high to array with smaller length
        int low = 0, high = n, medianPos = (n + m + 1) / 2;
        // cut 1 and cuut 2 represent this amount of number to take
        while(low <= high) {
            // we are applying cut to first array which is of smaller size
            int cut1 = low + (high - low) / 2;
            // on basis of cut1 we need to calculate cut2
            // (n1 + n2 + 1) / 2 , how many element needs to be in one half
            int cut2 = medianPos- cut1;
            
            // so cut2 and cut1 now have (n1 + n2 + 1) / 2 elements combined
            
            int left1 = cut1 == 0 ? INT_MIN: nums1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN: nums2[cut2 - 1];
            
            int right1 = cut1 == n ? INT_MAX: nums1[cut1];
            int right2 = cut2 == m ? INT_MAX: nums2[cut2];
            
            if(left1 <= right2 && left2 <= right1) {
                if((n + m) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return max(left1, left2);
                }
            }
            
            else if(left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        
        return 0.0;
    }
};