#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define N 2

typedef struct {    
    int **data;     
} Matrix;

Matrix create_matrix(){
    Matrix mat;    
    mat.data = (int**)malloc(N*sizeof(int*));
    for (int i=0;i < N;i++)
        mat.data[i] = (int*)malloc(N*sizeof(int));    
    return mat;
}

void free_matrix(Matrix *mat){
        for (int i=0;i < N;i++)
            free(mat->data[i]);
    free(mat->data);
}

void matrix_multiply_mod(Matrix* A, Matrix* B, Matrix* result, int mod)
{    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result->data[i][j] = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                result->data[i][j] = (result->data[i][j] + (A->data[i][k] * B->data[k][j]) % mod) % mod;
}


void matrix_power_mod(Matrix *matrix, Matrix *result, int power, int mod)
{    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result->data[i][j] = (i == j) ? 1 : 0;
    while(power){   
        if(power % 2 == 1){
            Matrix temp = create_matrix();
            matrix_multiply_mod(result, matrix, &temp, mod);
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    result->data[i][j] = temp.data[i][j];
            free_matrix(&temp);
        }        
        Matrix temp = create_matrix();
        matrix_multiply_mod(matrix, matrix, &temp, mod);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                matrix->data[i][j] = temp.data[i][j];
        free_matrix(&temp);
        power /= 2;
    }
}

int main() {
	int n = 0, m = 0;  
	int res;
    Matrix mymatrix = create_matrix();    
    Matrix result = create_matrix();
        
    res = scanf("%d%d%d%d%d%d", &mymatrix.data[0][0], &mymatrix.data[0][1],
                                &mymatrix.data[1][0], &mymatrix.data[1][1], &n, &m);
	assert(res==6);

    matrix_power_mod(&mymatrix, &result, n, m);
    printf("%d %d %d %d\n", result.data[0][0],result.data[0][1], result.data[1][0], result.data[1][1]);
    free_matrix(&mymatrix);
    free_matrix(&result);
    return 0;
}
