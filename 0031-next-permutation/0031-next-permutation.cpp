class Solution {
public:
    void reverse(vector<int> &arr, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--) {
            swap(arr[i], arr[j]);
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        
        //step 1: find break point -> arr[i] < arr[i+ 1] from back
        int n = nums.size();
        int bp = -1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                bp = i;
                break;
            }
        }
         
        // step 2: if break point does not exists 
        if(bp == -1) {
            reverse(nums, 0, n - 1);
            return;
        } 
        
        // step 3: when break points exists
        // find the elemnt in right half which is just greater
        int x = -1;
        for(int i = n - 1; i > bp; i--) {
            if(nums[bp] < nums[i]) {
                x = i;
                break;
            }
        }
        
        // step 4: swap the elements 
        swap(nums[bp], nums[x]);
        
        // step 5: reverse the right half of bp to get the next permutation
        reverse(nums, bp + 1, n - 1);
        
        return;
    }
};
// tc -> O(n)
// sc -> O(1)

// This will hold true for any string or number (in lexicographical order):
// breakpoint -> 1. difference between the current and next permutation 
// 2. right half of break point will be in decreasing order from bp or increasing order from back 

// if the elements are decresing order form the back then consider the n - 2 element as bp