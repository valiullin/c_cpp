#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


double get_elem(void *matr, int row, int col) {
    double elem = 0;
    double **arr = (double **)matr;
    elem = arr[row][col];
    return elem;
}

void set_elem(void *matr, int row, int col, double elem) {
    double **arr = (double **)matr;
    arr[row][col] = elem;
}

int main(int argc, char *argv[]) {
    assert(argc == 2); //more than 1 filename given
    FILE *f = fopen(argv[1], "r");
    assert(f); //file does not exist
 
    int rows_n, cols_n, elems_n;
    assert(fscanf(f, "%d %d %d",
      &rows_n, &cols_n, &elems_n) == 3);
 
    double **matrix = malloc(sizeof(double *) * rows_n);
    assert(matrix);
 
    for (int i = 0; i < rows_n; ++i) {
        matrix[i] = malloc(sizeof(double) * cols_n);
        assert(matrix[i]);
    }

    for (int i = 0; i < rows_n; ++i) {
        for (int j = 0; j < cols_n; ++j) {
            set_elem((void *)matrix, i, j, 0);
        }
    }
    
    int row, column;
    double value;
    for (int i = 0; i < elems_n; ++i) {
            assert(fscanf(f, "%d %d %lf", &row, &column, &value) == 3);
            assert(row-1 < rows_n && column-1 < cols_n);
            set_elem((void *)matrix, row-1, column-1, value);
            }

    assert(!fclose(f));

    double max_norm[rows_n];
    for(int i = 0; i < rows_n; ++i){
        for(int j = 0; j < cols_n; ++j){
            max_norm[i] += fabs(get_elem((void *)matrix, i, j));
        }
    }
    
    double max;
    for(int i = 0; i < rows_n; ++i){
        if(max < max_norm[i]) max = max_norm[i];
    }

    printf("%lf\n", max);

    for (int i = 0; i < rows_n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}
