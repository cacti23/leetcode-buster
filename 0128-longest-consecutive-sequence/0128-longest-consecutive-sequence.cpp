class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 1) return n;
        
        set<int> hashSet;
        
        // insert elements into hashset
        for(int i = 0; i < n; i++) {
            hashSet.insert(nums[i]);
        }
        
        int longestStreak = 0;
        // traverse the array 
        for(int i = 0; i < n; i++) {
            // in order to count the sequnce we need to know for sure that the element  is the starting element or not 
            // the below conditions checks if the element before nums[i] is not present then only we gonna move further
            if(!hashSet.count(nums[i] - 1)) {
                int currentNum = nums[i];
                int currentStreak = 1;
                
                while(hashSet.count(currentNum + 1)) {
                    currentStreak++;
                    currentNum++;
                }
                
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};
