func containsDuplicate(nums []int) bool {
    if len(nums) <= 1 {
        return false;
    }
    
    seen := make(map[int]struct{}); // only declaration
    // seen := map[int]struct{}{}; declaring and initialization
    
    for _, v := range nums {
        if _, ok := seen[v]; ok {
            return true;
        }
        
        seen[v] = struct{}{};
    }
    
    return false;
}