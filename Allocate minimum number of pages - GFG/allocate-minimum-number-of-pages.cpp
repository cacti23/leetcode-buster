//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int maxPages, int* arr,int n, int students) {
        
        // we need atleast one student here
        int cnt = 1;
        int pages = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > maxPages) return false;
            
            if(pages + arr[i] > maxPages) {
                // if at any point this execute means the old sum
                // was given to student before hence we made cnt start
                // from 1
                cnt++;
                pages = arr[i];
                
                if(cnt > students) return false;
            } else {
                pages += arr[i];
            }
        }
        
        return true;
        
    }
    //Function to find minimum number of pages.
    int findPages(int arr[], int N, int M) 
    {
        // if the number of books is less than students
        if(N < M) return -1;
        
        // if we consider this array 12, 34, 67 and 90
        // minimum number of pages can be 12 which student can have 
        // maximum number of pages can be 203 which student can have
        
        // find the maximum value
        int totalPages = 0;
        for(int i = 0; i < N; i++) {
            totalPages += arr[i];
        }
        
        // now we have a serach space 
        int low = arr[0], high = totalPages;
        
        // now for each mid point we will try to distribute the books
        // such that each student should get one book atleast 
        // the number of pages does not exceed the mid point
        // and the number of student can be max M;
        
        int ans = INT_MAX;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(isPossible(mid, arr,N, M)) {
                // if this is possible try to find the minimum value
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if(ans == INT_MAX) return -1;
        
        return ans;
    }
};

// tc -> O(nlogn)
// sc-> O(1)


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends