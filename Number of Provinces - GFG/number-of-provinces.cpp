//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1;
        
        for(auto it: adj[node]) {
            if(!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }   
  
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjList[V];
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        vector<int> visited(V + 1, 0);
        
        int num_provinces = 0;
        
        // make sure to iterate over all the node since theh graph is disconnected
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, adjList, visited);
                num_provinces++;
            }
        }
        
        return num_provinces;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends