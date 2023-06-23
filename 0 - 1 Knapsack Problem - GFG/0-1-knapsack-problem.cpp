//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int maxWeight, int wt[], int val[], int n) 
    { 
        // declare a dp matrix 
        // declare a dp matrix 
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));


        // base case 
        for(int w = wt[0]; w <= maxWeight; w++) dp[0][w] = val[0];
        
        // loop for index
        for(int i = 1; i < n; i++) {
            for(int w = 0; w <= maxWeight; w++) {
                int notTake = 0 + dp[i - 1][w];
                
                int take = INT_MIN;
                
                if(wt[i] <= w) {
                    take = val[i] + dp[i - 1][w - wt[i]];
                }
        
                dp[i][w] = max(notTake, take);
            }
        }
        
        
        return dp[n - 1][maxWeight];
    }
};

// tc -> O(n * w)
// sc -> O(n * w) + O(n)


//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends