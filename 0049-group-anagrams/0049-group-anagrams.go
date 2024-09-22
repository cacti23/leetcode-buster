func groupAnagrams(strs []string) [][]string {
    am := make(map[[26]int][]string)
    
    for _, s := range strs {
        var co[26]int
        for _, c := range s {
            co[c - 'a']++;
        }
        
        // anagramMap[count] intially will be an empty array 
        am[co] = append(am[co], s)
    }
    
    re := make([][]string, 0, len(am));
    for _, v := range am {
        re = append(re, v)
    }
    
    return re
}