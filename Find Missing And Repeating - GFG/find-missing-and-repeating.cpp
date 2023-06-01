//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int xr = 0; // 0 because its kind like identity thing 
        // even number : 2 ^ 2 = 0
        // odd Number : 2 ^ 2 ^ 2 = 2
        
        // find xor for elements of the array and element from 1 to n
        for(int i = 0; i < n; i++) {
            xr = xr ^ arr[i];
            xr = xr ^ (i + 1);
        }
        
        // now xr = x ^ y where x is repeating and y is missing number
        // repeating number will comes odd i.e three times when we xor all element and missing elements will comes odd i.e one 
        
        // now we need to find the first set bit of the xor number , we need a number who only contains 
        // first set bit of the xr number 
        
        int bitIndex = 0;
        
        while(1) {
            if((xr & ( 1 << bitIndex)) != 0) {
                break;
            }
            
            bitIndex++;
        }
        
        int number = 1 << bitIndex;
        
        // now we have the index for the first bit element 
        // now need to segrregate the elements form array and 1 to n into group whos this bit index is zero or set 
        
        int zero = 0;
        int one = 0;
        
        for(int i = 0; i < n; i++) {
            if((arr[i] & number) != 0) {
                one = one ^ arr[i];
            } else {
                zero = zero ^ arr[i];
            }
            
            if(((i + 1) & number) != 0) {
                one = one ^ (i + 1);
            } else {
                zero = zero ^ (i + 1);
            }
        }
        
        // after this for loop one and zero will have one of the missing or repearing number 
        // find thos number 
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == one) cnt++;
        }
        
        if(cnt == 2) return { one, zero}; // { repeating, missing }
        return { zero, one };
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends