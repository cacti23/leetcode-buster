func generateParenthesis(n int) []string {
    result := []string{}
    
    return backtrack(n, "", 0, 0, result)
}

func backtrack(n int, current string, open, close int, result []string) []string {
    // base case: if we have a valid combination
    if len(current) == 2 * n {
        result = append(result, current)
        return result
    }
    
    // Add 'C' if we have open paranthese available
    if open < n {
        result = backtrack(n, current + "(", open + 1, close, result)
    }
    
    // add ")" if there are unmatched open paraenthese
    if close < open {
        result = backtrack(n, current + ")", open, close + 1, result)
    }
    
    return result
}