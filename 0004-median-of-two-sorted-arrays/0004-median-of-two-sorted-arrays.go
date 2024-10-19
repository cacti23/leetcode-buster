func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    n1 := len(nums1)
    n2 := len(nums2)
    
    // we want n1 to be smaller
    if n1 > n2 {
        // swap the array
        return findMedianSortedArrays(nums2, nums1) 
    }
    
    // n1 is now smaller
    n := n1 + n2
    // calculate the size of left half
    // in case of odd element i want the left half to have more element than right half hence using the below formula
    leftLen := (n1 + n2 + 1) / 2
    
    // we will apply binary search in smaller elements
    l, r := 0, n1
    
    for l <= r {
        mid1 := (l + r) / 2
        mid2 := leftLen - mid1
        // calculate l1, l2, r1 & r2
        l1, l2 := math.MinInt, math.MinInt
        r1, r2 := math.MaxInt, math.MaxInt
        
        // check if mid1 & mid2 is inbounds with array then only set values for r1 & r2
        if mid1 < n1 {
            r1 = nums1[mid1]
        }
        
        if mid2 < n2 {
            r2 = nums2[mid2]
        }
        // check if mid1 - 1 & mid2 - 1 is inbounds with array then only set values for 
        if mid1 - 1 >= 0 {
            l1 = nums1[mid1 - 1]
        }
        
        if mid2 - 1 >= 0 {
            l2 = nums2[mid2 - 1]
        }
        
        if l1 <= r2 && l2 <= r1 {
            // odd length
            if n % 2 == 1 {
                return float64(max(l1, l2))
            } else { // even length
                e1 := max(l1, l2)
                e2 := min(r1, r2)
                return (float64(e1 + e2) / 2)
            }
        } else if l1 > r2 {
            r = mid1 - 1
        } else {
            // l2 > r1
            l = mid1 + 1
        }
    }
    return 0
}