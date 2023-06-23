//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

	public:
	int minCoins(int coins[], int n, int target) 
	{ 
	    // coins index and target
	    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
	    
	    // base case 
	    for(int t = 0; t <= target; t++) {
	        if(t % coins[0] == 0) dp[0][t] = t / coins[0];
	        else dp[0][t] = 1e9; 
	    }
	    
	    // for any number of changing parameter write that much nested loop
	    for(int i = 1; i < n; i++) {
	        for(int t = 0; t <= target; t++) {
        	   int notTake = 0 + dp[i - 1][t]; 
        	   
        	    // if we take the current coin
        	    int take = INT_MAX;
        	    // target multiple for current coin
        	    if(coins[i] <= t) {
        	        // every time in case of unlimited supply 
        	        // make sure to call take on same index
        	        
        	        take = 1 + dp[i][t - coins[i]];
        	    }
        	    
        	    dp[i][t] = min(notTake, take);
	        }
	    }
	   
	   
	    if(dp[n - 1][target] >= 1e9) return -1;
	    
	    return dp[n - 1][target];
	} 
	  
};

// tc -> > O(N * T)
// sc ->  O(N * T) 


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends