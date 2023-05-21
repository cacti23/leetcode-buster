class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // this is inbuilt function in c++ to calculate the next permutation
        next_permutation(nums.begin(), nums.end());
    }
};