//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

	public:
	int solve(int i, int target, int* coins, vector<vector<int>> &dp) {
	    // base case
	    if(i == 0) {
	        // here if we have not met the target we have to meet it here
	        // this condition makes sure that this coin can help to meet the target
	        if(target % coins[i] == 0) {
	            // now count the number of coins that will be required to meet the tawrget
	            int multiple = target / coins[0];
	            return multiple;
	        }
	        // means this last coin cannot help to achieve the target
	        // return INT_MAX coin because we are taking min
            return 1e9;
	    }
	    
	    if(dp[i][target] != -1) return dp[i][target];
	    
	  
	   int notTake = 0 + solve(i - 1, target, coins, dp); 
	   
	    // if we take the current coin
	    int take = INT_MAX;
	    // target multiple for current coin
	    if(coins[i] <= target) {
	        // every time in case of unlimited supply 
	        // make sure to call take on same index;
	        take = 1 + solve(i , target - coins[i], coins, dp);
	    }
	    
	    dp[i][target] = min(notTake, take);
	    
	    return dp[i][target];
	    
	    
	}
	int minCoins(int coins[], int n, int target) 
	{ 
	    // coins index and target
	    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
	    
	    int ans = solve(n - 1, target, coins, dp);
	    
	    if(ans >= 1e9) return -1;
	    
	    return ans;

	} 
	  
};

// tc -> > O(N * T)
// sc ->  O(N * T) + O(T)


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