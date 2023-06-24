//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
    void solve(vector<int>& arr, int i , vector<int> &ans, int sum) {
        // base case
        if(i < 0) {
            // after drawing binary tree it is you will kno wthat 
            // insert sum that this points
            ans.push_back(sum);
            return;
        }
        
        // not select the element 
        solve(arr, i - 1, ans, sum);
        
        // select the element
        solve(arr, i - 1, ans, sum + arr[i]);

        return;
    }

    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        
        int sum = 0;
        
        solve(arr, n - 1, ans, sum);
        
        return ans;    
    }
};





//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends