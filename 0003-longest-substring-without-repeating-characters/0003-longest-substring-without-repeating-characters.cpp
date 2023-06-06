class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        if(n <= 1) return n;

        int maxLen = INT_MIN;
        // element, index
        unordered_map<int, int> hashMap;

        int l = 0;
        for(int r = 0; r < n; r++) {
            // if elemenet is not present in map 
            if(hashMap.find(s[r]) == hashMap.end()) {
                // insert the element & index into the map
                hashMap[s[r]] = r;
            } else {
                // if the element is found means between l and r
                // there is a repeating element
                // so we keep on skip L to repeating element index + 1
                if(l < hashMap[s[r]] + 1) l = hashMap[s[r]] + 1;
                
                // update the index of the element in hashmap
                hashMap[s[r]] = r;            
            }

            // after executing above if else it will be 100 %
            // there will be no repeating element in between l and r
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

// tc -> O(n)
// sc -> O(1)