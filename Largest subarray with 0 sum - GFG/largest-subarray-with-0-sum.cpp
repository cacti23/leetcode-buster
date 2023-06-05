//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // using hash map approach 
        unordered_map<int, int> umap;
        // key prefix sum and value index
        
        int maxi = 0;
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            
            if(sum == 0) maxi = i + 1;
            else {
                 // if the sum is present in umap
                if(umap.find(sum) != umap.end()) {
                    int sumIndex = umap[sum];
                    
                    maxi = max(maxi, i - sumIndex);
                }
                // if the sum is not present in umap
                else {
                    umap[sum] = i;
                }
            }
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends