class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        if(n <= 1) return n;
        
        // use two pointer and hash set 
        unordered_set<int> uset;
        
        int maxi = INT_MIN;
        
        int left = 0; // denote starting character

        for(int right = 0; right < n; right++) {
            // if the element is not present in the set 
            if(uset.find(s[right]) == uset.end()) {
                // means repeating charcter is not present between l and r 
                maxi = max(maxi, right - left + 1);
                uset.insert(s[right]);
            }       
            // if the element is present in the set
            else {
                // means that repeating element can be between l and r 
                // increment l till that character is removed form 
                while(uset.find(s[right]) != uset.end() && left < right) {
                    uset.erase(s[left]);
                    left++;
                }
                
                // now there is no repeating character between l and r
                // this line is added becuase we are using for loop
                uset.insert(s[right]);
            }
        }
        
        return maxi;
    }
};