//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int solve(int W, int wt[], int val[], int i, vector<vector<int>> &dp) {
        // base case 
        if(i < 0) return 0;
        
        // if the value is already stored in dp 
        if(dp[i][W] != -1) return dp[i][W];
        
        
        int notTake = 0 + solve(W, wt, val, i - 1, dp);
        int take = INT_MIN;
        if(wt[i] <= W) {
            take = val[i] + solve(W - wt[i], wt, val, i - 1, dp);
        }
        
        dp[i][W] = max(notTake, take);
        
        return dp[i][W];
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // declare a dp matrix 
        // declare a dp matrix 
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        
        // insitallize the dp matrix 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < W + 1; j++) {
                dp[i][j] = -1;
            }
        } 
        
        
        return solve(W, wt, val, n - 1, dp);
    }
    
   
};


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