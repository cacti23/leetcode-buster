//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // using binary serach with cut1 and cut2 
        // postion cut1 and cut2 such that left right elements are smaller than
        // right side element and left elements number should be equal to k
        
        // apply binary search in in array with smaller len gth 
        if(n < m) {
           return kthElement(arr2, arr1, m, n, k);
        }
        // since we are applying cut we need to keep h = n 
        // if cut is 0 then no element is there 
        // if cut is n then all elements are there
        
        // where are choosing max(0, k - m) because if k is greateer than
        // here in the case we have start from atleast k elements from arr1 and arr2
        int low = max(0,k-m);
        
        // small array will always gives less elements only
        int high = min(n, k);
        
        while(low <= high) {
            int cut1 = low + (high - low) / 2;
            // need to make sure on left side of both cut number of elements should be k
            int cut2 = k - cut1;
            
            // need to make sure the element on left is smaller than elements on right 
            int left1 = cut1 == 0 ? INT_MIN: arr1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN: arr2[cut2 - 1];
            
            int right1 = cut1 == n ? INT_MAX: arr1[cut1];
            int right2 = cut2 == m ? INT_MAX: arr2[cut2];
            
            if(left1 <= right2 && left2 <= right1) {
                return max(left1, left2);
            } else if(left2 > right1) {
                low = cut1 + 1;
            } else {
                high = cut1 - 1;
            }
        }
        
        return -1;
        
    }
};


//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends