/**
 Do not return anything, modify matrix in-place instead.
 */
function rotate(matrix: number[][]): void {
    let n = matrix.length;
    
    for(let i = 0; i < n; i++) {
        for(let j = 0; j < n; j++) {
            if(i < j) {
                swap(matrix, i, j);
            }
        }
    }

    // reverse each row
    for(let i = 0; i < n; i++) {
        let j = 0, k = n - 1;
        while(j < k) {
            let temp = matrix[i][j];
            matrix[i][j] = matrix[i][k];
            matrix[i][k] = temp;
            j++;
            k--;
        }
    }

    return;
};

function swap(matrix: number[][], i: number, j: number): void {
    let temp = matrix[i][j];
    matrix[i][j] = matrix[j][i];
    matrix[j][i] = temp;
}

// tc -> O(n^2)