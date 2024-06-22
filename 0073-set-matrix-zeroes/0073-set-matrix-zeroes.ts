/**
 Do not return anything, modify matrix in-place instead.
 */
function setZeroes(matrix: number[][]): void {
    let n = matrix.length;
    let m = matrix[0].length;
    let row = new Array(n).fill(false);
    let col = new Array(m).fill(false);

    for(let i = 0; i < n; i++) {
        for(let j = 0; j < m; j++) {
            if(matrix[i][j] === 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }


    // now update rows and cols of matrix 
    for(let i = 0; i < n; i++) {
        for(let j = 0; j < m; j++) {
            if(row[i] == true || col[j] == true) {
                matrix[i][j] = 0;
            }
        }
    }
};

// tc -> O(m x n)
// sc -> O(m + n)