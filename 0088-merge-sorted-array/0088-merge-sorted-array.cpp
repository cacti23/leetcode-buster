class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        // step 1: setup gap and instialize 
        int gap = ((n + m) / 2) + ((n + m) % 2);
        
        // step 2: loop through gap 
        while(gap > 0) {
            // step a: setup left and right 
            int left = 0; 
            int right = left + gap;
            
            // step b: loop through right
            while(right < (n + m)) {
                // step b: write cases   
                // case 1: in nums1 and nums2 
                if(left < n && right >= n && nums1[left] > nums2[right - n]) {
                    swap(nums1[left], nums2[right - n]);
                } 
                // case 2: both in num2
                else if(left >= n && nums2[left - n] > nums2[right - n]) {
                    swap(nums2[left - n], nums2[right -n]);
                }
                // case 3: both in nums1
                else if(right < n && nums1[left] > nums1[right]) {
                    swap(nums1[left], nums1[right]);
                }
                
                left++;
                right++;
            }
            
            if(gap == 1) break;
            
            gap = (gap / 2) + (gap % 2);
        }
        
        // step 3: copy elements from num2 to nums1
        for(int i = 0; i < m; i++) {
            nums1[n + i] = nums2[i];
        }
        
        return;
        
    }
};