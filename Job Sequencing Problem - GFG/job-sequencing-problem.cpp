//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/


class Solution 
{
    public:
    static bool comparator(Job a, Job b) {
        if(a.profit > b.profit) return true;
        else return false;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // sort the jobs array in descending order of profit
        sort(arr, arr + n, comparator);
        // we want to perform those job first that offer maximum profit
        // in order to maximise the profit we should do try to do each job
        // on deadline day itself to accomodate as many job possible
        
        // now create a slot array that will store the id of 
        // jobs that needs to be performed on that day
        // first find the maximum  deadline day
        int maxDeadline = -1;
        
        for(int i = 0; i < n; i++) {
            maxDeadline = max(arr[i].dead, maxDeadline);
        }
        
        // intialize array using maxDeadline
        int slot[maxDeadline + 1] = {false};
        
        int countJobs = 0, jobProfit = 0;
        
        // outer loop will iterate through all jobs
        for(int i = 0; i < n; i++) {
            // intialize j to check if the last deadline day slot is empty or not
            for(int j = arr[i].dead; j > 0; j--) {
                if(slot[j] == false) {
                    slot[j] = true;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int> result;
        result.push_back(countJobs); // add count of jobs to the vector
        result.push_back(jobProfit); // add job profit to the vector
        
        return result;
    } 
};

// tc -> O(n logn) + O(n*m) , where n are jobs and m deadlines
// sc -> O(m) 


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends