func isValid(s string) bool {
    n := len(s)
    
    // wrost case capacity
    st := make([]rune, 0, n)
    
    for _, ch := range s {
       if ch == '(' || ch == '[' || ch == '{' {
            st = append(st, ch)
        } else {
           if len(st) == 0 {
               return false
           }
           
           top := st[len(st) - 1]
           st = st[:len(st) - 1]
           
           if ch == ')' && top != '(' || ch == ']' && top != '[' || ch == '}' && top != '{' {
                return false
            }
        }
    }
    
    return len(st) == 0
}

