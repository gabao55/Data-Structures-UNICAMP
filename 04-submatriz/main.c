#include <stdio.h>

int main() {
    int row_start, column_start;
    int n, m, r, s, i, j, sum = 0, max_sum = 0;

    scanf("%d %d %d %d", &n, &m, &r, &s);

    int M[n][m];

    // Scanning the input matrix M
    for ( i = 0 ; i < n ; i++ ) {
        for ( j = 0 ; j < m ; j++ ) {
            scanf("%d", &M[i][j]);
        }
    }

    // Going through the matix M rows and columns untill the limit of the submatrix
    for ( row_start = 0 ; row_start <= (n - r) ; row_start++ ) {
        for ( column_start = 0 ; column_start <= (m - s) ; column_start++ ) {
            // Going through the submatrix
            for ( i = row_start ; i < (row_start + r) ; i++ ) {
                if ( column_start == 0 ) {
                    for ( j = column_start ; j < (column_start + s) ; j++ ) {
                        sum += M[i][j];
                    }
                }
                else {
                    sum -= M[i][column_start - 1];
                    sum += M[i][column_start + s - 1];
                }
            }
            // Computing the highest sum value in matrix M
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
        sum = 0;
    }

    printf("%d\n", max_sum);
    return 1;
}
