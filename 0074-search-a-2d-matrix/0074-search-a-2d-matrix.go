func searchMatrix(matrix [][]int, target int) bool {
    // the solution is to map the linear index to matrix index
    n := len(matrix)
    m := len(matrix[0])
    
    l := 0
    r := n * m
    
    for l <= r {
        mid := (l + r ) / 2
        
        // get row and col index
        rInd := mid / m
        cInd := mid % m
        
        if rInd >= n || cInd >= m {
            return false
        }
        
        if matrix[rInd][cInd] == target {
            return true
        } else if matrix[rInd][cInd] < target {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    
    return false
}

// TC -> O(log(m*n))
// SC -> O(1)