class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(); // number of intervals present 
        
        // step 1: sort the intervals matrix
        sort(intervals.begin(), intervals.end());
        
        // step 2: insert the first intervals into ans;
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i = 1; i < n; i++) {
            int startTemp = intervals[i][0]; 
            int endTemp = intervals[i][1];
            
            if(startTemp <= ans.back()[1]) {
                // overlapping is there 
                // update the end of interval in ans matrix
                ans.back()[1] = max(ans.back()[1], endTemp);
            } else {
                ans.push_back({startTemp, endTemp});
            }
        }
        
        return ans;
    }
};