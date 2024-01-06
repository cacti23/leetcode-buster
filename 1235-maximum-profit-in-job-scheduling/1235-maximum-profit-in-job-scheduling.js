/**
 * @param {number[]} startTime
 * @param {number[]} endTime
 * @param {number[]} profit
 * @return {number}
 */
var jobScheduling = function(startTime, endTime, profit) {
    // combining all given arrays into one
    const n = startTime.length;
    const jobs = Array.from({length: n}, (_, i) => [startTime[i], endTime[i], profit[i]]);
    // store the profit of dfs returning for index i
    const dp = new Array(n).fill(-1);// it can also be called as cache
    
    // sort basis on startTime
    jobs.sort((a , b) => a[0] - b[0]);
    
    let res = 0;
    
    const dfs = function(i) {
        // base case
        if(i === jobs.length) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        // include the element at the index
        const [_, endTime, profit] = jobs[i];
        // find the next nearest start time
        const j = findNextStartTime(jobs, i);
        // current profit is added and dfs for next element is called
        const pick = profit + dfs(j);
        // don't include the element at index i move to next index
        const notPick = dfs(i + 1);
        // memoization
        dp[i] =  Math.max(pick, notPick);
        return dp[i];
    }
    
    return dfs(0);
};

const findNextStartTime = function(jobs, target) {
    let low = target;
    let high = jobs.length - 1;
    
    while(low <= high) {
        const mid = Math.floor((high - low) / 2 + low);
        // if we found endTime of current job being less than or equal to the startTime of next job
        if (jobs[target][1] <= jobs[mid][0]) {
            high = mid - 1; // Search in the left half means try to find the lowest of the startTime that is just greater then the endTIme of current task
        } else {
            low = mid + 1; // Search in the right half
        }
    }
    
    return low;
}