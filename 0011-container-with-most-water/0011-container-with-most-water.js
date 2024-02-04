/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let area = 0;
    let i = 0, j = height.length - 1;
    
    while(i < j) {
        const h = Math.min(height[i], height[j]);
        area = Math.max(area, h * (j - i));
        // find the next taller line
        while(height[i] <= h && i < j) i++;
        while(height[j] <= h && i < j) j--;
    }
    
    return area;
};

// Begin with the widest container, considering the first and last lines.
// Other containers are narrower, requiring greater height for more water.
// Skip lines at both ends that cannot support taller containers.
// Evaluate the new container obtained.
// Continue until no more containers remain.

// tc -> O(n)
// sc -> O(1)