class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        int m = nums2.size();
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(nums1[i] == nums2[j]) {
                    if(j == m - 1) {
                        ans.push_back(-1);
                        break;
                    }
                    
                    // find next greater element in nums2
                    int size = ans.size();
                    for(int k = j + 1; k < m; k++) {
                        if(nums2[k] > nums2[j]) {
                            ans.push_back(nums2[k]);
                            break;
                        }
                    }
                    
                    if(size == ans.size()) {
                        ans.push_back(-1);
                    }
                    
                    break;
                }
            }
        }
        
        return ans;
    }
};

// tc -> O(n * m)
// sc -> O(1)