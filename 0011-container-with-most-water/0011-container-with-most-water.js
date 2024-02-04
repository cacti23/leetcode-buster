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
        if (height[i] < height[j]) i++;
	    else j--;
    }
    
    return area;
};
// tc -> O(n)
// sc -> O(1)