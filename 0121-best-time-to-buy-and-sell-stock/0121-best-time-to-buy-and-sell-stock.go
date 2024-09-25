func maxProfit(prices []int) int {
    // we will simultaneously find min and calulcate the max profit 
    // two pointers approach
    min := math.MaxUint32 
    res := 0
    
    for _, price := range prices {
        if price > min {
            res = max(res, price - min)
        } else {
            min = price
        }
    }
    
    return res
}