//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // traverse the array once to find the second largest element 
	    int largest = INT_MIN;
	    int secondLargest = INT_MIN;
	   
	    for(int i = 0; i < n; i++) {
	        // if element is greater than the largest update both
	        if(arr[i] > largest) {
	            secondLargest = largest;
	            largest = arr[i];
	        } 
	        // if the elemtn is not greter than the largest then check whether to update second largest
	        else if(arr[i] < largest) {
	            if(secondLargest == INT_MIN || secondLargest < arr[i]) {
	                secondLargest = arr[i];
	            }
	        }
	    }
	    
	    if(secondLargest == INT_MIN) return -1;
	    
	    return secondLargest;
	    
	
	}
};

// tc -> O(n)
// sc -> O(1)

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends