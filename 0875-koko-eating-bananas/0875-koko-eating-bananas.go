func minEatingSpeed(piles []int, h int) int {
    // find the maximum value 
    mVal := math.MinInt
    
    for _, v := range piles {
        mVal = max(mVal, v)
    }
        
    // after find the max value we have a search space to apply binary search 
    l, r, ans := 1, mVal, 0
    var m int
    
    for l <= r {
        m = (l + r) / 2
        
        if canEat(piles, h, m) {
            ans = m
            r =  m - 1
        } else {
            l = m + 1
        }
    }
    
    return ans
}

func canEat(piles []int, timeLimit, speed int) bool {
    timeNeeded := 0
    
    for _, banana := range piles {
        // this is a trick top round up the number 
        // imagine 3 bananas are there and speed is 6 if we do  3 / 6 we get 0
        // in integer division
        timeNeeded += (banana + speed - 1) / speed
        if timeNeeded > timeLimit {
            return false
        }
    }
    
    return true
}
 
// tc -> O(logn * m)