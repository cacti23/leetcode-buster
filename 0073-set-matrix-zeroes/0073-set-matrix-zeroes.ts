/**
 Do not return anything, modify matrix in-place instead.
 */
function setZeroes(matrix: number[][]): void {
    let n = matrix.length;
    let m = matrix[0].length;

    // using 1st row and col as to store if zero exists or not
    // 1st row will store the zeros present in cols 
    // 1st col will store the zeros present in rows
    let rowHasZero = false;
    let colHasZero = false;

    // check if 1st row has zero
    // means changing value of col
    for(let j = 0; j < m; j++) {
        if(matrix[0][j] == 0) {
            rowHasZero = true;
            break;
        }
    }

    // check if 1st col has zero
    // means changing value of row
    for(let i = 0; i < n; i++) {
        if(matrix[i][0] == 0) {
            colHasZero = true;
            break;
        }
    }

    // now for the rest of the matrix
    for(let i = 1; i < n; i++) {
        for(let j = 1; j < m; j++) {
            if(matrix[i][j] == 0) {
                // row update
                // since col zero store row
                matrix[i][0] = 0;
                // col update
                // since row zero store col
                matrix[0][j] = 0;
            }
        }
    }
    
    // now set zeros for the matrix
    for(let i = 1; i < n; i++) {
        for(let j = 1; j < m; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // if rowHasZero is true set the first the first row as zero
    if(rowHasZero) {
        for(let j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    if(colHasZero) {
        for(let i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return;
};

// tc -> O(mxn)
// sc -> O(1)