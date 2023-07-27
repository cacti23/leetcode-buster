//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        // use hashMap
        map<int, int> freq;
        
        // traverse the array a
        for(int i = 0; i < n; i++) {
            freq[a[i]]++;
        }
        
        // travserse the array b
        for(int i = 0; i < m; i++) {
            freq[b[i]]++;
        }
        
        // count the elements in the union
        return freq.size();
    }
};

// tc -> O(nlogn) + O(mlogm)
// sc -> O(max(n, m))


//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends