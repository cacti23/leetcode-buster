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
        // using two pointers when the array is sorted
        int cnt = 0;
        
        sort(a, a + n);
        sort(b, b + m);
        
        int i = 0, j = 0;
        vector<int> unionArr;
        
        while(i < n && j < m) {
            if(a[i] <= b[j]) {
                if(unionArr.size() == 0 || unionArr.back() != a[i]) {
                    unionArr.push_back(a[i]);
                }
                
                i++;
            } else {
                if(unionArr.size() == 0 || unionArr.back() != b[j]) {
                    unionArr.push_back(b[j]);
                }
                
                j++;
            }
        }
        
        // check the remaining element 
        while(i < n) {
            if(unionArr.size() == 0 || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            
            i++;
        }
        
        while(j < m) {
            if(unionArr.size() == 0 || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            
            j++;
        }
        
        return unionArr.size();
    }
};

// did not count the time complexity of sorting function

// tc -> O(n + m)
// sc -> O(1)


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