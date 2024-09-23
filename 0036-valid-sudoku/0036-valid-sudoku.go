func isValidSudoku(board [][]byte) bool {
    hashMap := make(map[string]bool)
    
    for row := 0; row < 9; row++ {
        for col := 0; col < 9; col++ {
            
            currVal := string(board[row][col])
            
            if(currVal == ".") {
                continue
            }
            
            _, ok1 := hashMap[currVal + "found in row" + string(row)]
            _, ok2 := hashMap[currVal + "found in col" + string(col)]
            _, ok3 := hashMap[currVal + "found in grid" + string(row/3) + "-" + string(col/3)]
            
            if ok1 || ok2 || ok3 {
                return false
            } else {
                hashMap[currVal + "found in row" + string(row)] = true
                hashMap[currVal + "found in col" + string(col)] = true
                hashMap[currVal + "found in grid" + string(row/3) + "-" + string(col/3)] = true
            }
        }
    }
    
    return true
}

// tc -> O(n^2) -> O(9^2) -> O(81) -> O(1)
// sc -> O(n^2) -> O(9^2) -> O(81) -> O(1)