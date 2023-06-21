//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// intuiution is 
    	// increment the count by one when the train arrives 
    	// decrement the count by one when the train left the station 

    	// maximum time that can is possible 2360
    	vector<int> v(2361, 0);
    	
    	
    	// iterate over the arrival and departure array 
    	for(int i = 0; i < n; i++) {
    	    // at this time the train is reached the station
    	    // means at that time platform will be required
    	    v[arr[i]]++;
    	    // for departure at the departure time the train is at the station 
    	    // hence we will require one platform atleast
    	    // so we decrement the value for the next minute
    	    v[dep[i] + 1]--;
    	}
    	
    	int count = 0;
    	int maxPlatforms = 0;
    	
    	// add the count to value and check the maximum count
    	for(int i = 0; i < 2361; i++) {
    	    count += v[i];
    	    
    	    maxPlatforms = max(count, maxPlatforms);
    	}
    	
    	return maxPlatforms;
    }
};

// tc -> O(n) + O(n) ~ O(n)
// sc -> O(1) , becuase max 2361 elements will be there


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends