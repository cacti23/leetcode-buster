func isPalindrome(s string) bool {
    i := 0
    j := len(s) - 1
    arr := []rune(s)
    
    for i < j {
        iVal := unicode.ToLower(arr[i])
        jVal := unicode.ToLower(arr[j])
        
        if !isLetterOrDigit(iVal) {
            i++
            continue
        }
        
        if !isLetterOrDigit(jVal) {
            j--
            continue
        }
        
        if iVal != jVal {
            return false
        }
        
        i++
        j--
    }
    
    return true
}

func isLetterOrDigit(r rune) bool {
    return unicode.IsLetter(r) || unicode.IsDigit(r)
}

