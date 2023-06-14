class Solution {
public:
    int strStr(string haystack, string needle) {
        // using two for loops 
        int hLen = haystack.size();
        int nLen = needle.size();
        
        // outer loop select all possible starting points in haystack
        for(int i = 0; i <= hLen - nLen; i++) {
            // will loop through needle
            int j = 0;
            for(; j < nLen; j++) {
                if(haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if(j == nLen) return i;
        }
        
        return -1;
    }
};

// tc -> O(n*m)
// sc -> O(1)