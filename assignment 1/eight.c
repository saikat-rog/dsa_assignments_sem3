// 8. Write a program to multiply any two matrixes.

#include <stdio.h>
void main()
{
    int a[3][3], b[3][3], c[3][3];
    int i, j, k;
    printf("Enter the elements of first matrix\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("a[%d][%d]: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of second matrix\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("a[%d][%d]: ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
        printf("The product of two matrixes is\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d\t", c[i][j]);
            }
        }
    }
}