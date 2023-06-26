//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countSmallerThanMid(vector<int> &row, int mid) {
        int low = 0, high = row.size() - 1;
        
        while(low <= high) {
            int md = low + (high - low) / 2;
            
            if(row[md] <= mid) {
                low = md + 1;
            } else {
                high = md - 1;
            }
        }
        
        return low;
        
    }

    int median(vector<vector<int>> &matrix, int r, int c){
        // find the minimum element
        // search the first column
        int mini = INT_MAX;
        for(int i = 0; i < r; i++) {
            // only row is changing but col is still there
            if(matrix[i][0] < mini) {
                mini = matrix[i][0];
            }
        }
        
        // find the maximum element
        // serach the last column
        int maxi = INT_MIN;
        for(int i = 0; i < r; i++) {
            // only row is changing but col is still there
            if(matrix[i][c - 1] > maxi) {
                maxi = matrix[i][c- 1];
            }
        }
        
        // low will be mini and high will be maxi 
        int low = mini;
        int high = maxi;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            // mid is acting as a index rather than element
            // find the elements smaller than mid
            // for each row 
            int cnt = 0;
            for(int i = 0; i < r; i++) {
                cnt += countSmallerThanMid(matrix[i], mid);
            }
            
            if(cnt <= (r * c) / 2) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low;
        
    }
};

//


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends