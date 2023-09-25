// 1) Write a programme to print the sum of the diagonal element of the MxN Square Matrix.
#include<stdio.h>
void main(){
    int dim, a[50][50], sum = 0;
    printf("Enter matrix dim: ");
    scanf("%d", &dim);
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%d ", &a[i][j]);
        }
    }

    for (int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++){
            if (i == j){
               sum = sum + a[i][j];
            }  
        }
    }
    printf("The sum: %d", sum);
}