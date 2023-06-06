class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        if(n <= 1) return n;
        
        int maxi = INT_MIN;
        
        // outer loop to select the starting point
        for(int i = 0; i < n; i++) {
            unordered_set<int> uset;
            // inner loop to get string starting with s[i]
            int j = i;
            for(; j < n; j++) {
                // if element exists calculate max and break the loop
                if(uset.find(s[j]) != uset.end()) {
                    maxi = max(maxi, j - i);
                    break;
                }
                
                uset.insert(s[j]);
            }
            
            // if j becomes n means in that substring there was no repeating element 
            if(j == n) maxi = max(maxi, j - i);
        }
        
        // if maxi is INT_MIN meaning there are not repeating characters in string
        if(maxi == INT_MIN) return n;
        
        return maxi;
        
    }
};