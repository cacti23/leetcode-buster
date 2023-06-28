class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // solved using stack 
        stack<int> st;
        
        int n = nums1.size();
        int m = nums2.size();
        
        unordered_map<int, int> umap;
        vector<int> ans;
        
        // setup nge array 
        for(int i = m - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            
            if(st.empty()) umap[nums2[i]] = -1;
            else umap[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }
        
        // iterate over nums1 to find the next greater element 
        for(int i = 0; i < n; i++) {
            ans.push_back(umap[nums1[i]]);
        }
        
        return ans;
    }
};

