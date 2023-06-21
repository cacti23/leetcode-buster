//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // the main intuition here is that if the meeting gets over quickly
        // we can arrange a lot of meeting one by one
        
        // create a vector to store the meeting pair
        vector<pair<int,int>> meet;
        
        // we are inserting end before start because default sorting will
        // happen on basis of first element
        for(int i = 0; i < n; i++) {
            meet.push_back({end[i], start[i]});
        }
        
        // now the array will be sorted on basis of first element
        sort( meet.begin(), meet.end());
        
        // first meeting will happen for sure 
        int noOfMeets = 1;
        int lastendmeet = meet[0].first;
        
        for(int i = 1; i < n; i++) {
            // here we are checking that the start time of next meeting is greater
            // than the last meeting end time
            if( meet[i].second > lastendmeet) {
                
                lastendmeet = meet[i].first;
                noOfMeets++;
            }
        }
        
        return noOfMeets;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends