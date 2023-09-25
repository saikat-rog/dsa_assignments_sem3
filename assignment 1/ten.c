// 10.Write a C program to accept 5 numbers, store them in array and find out the smallest number using pointer.

#include<stdio.h>
void main(){
    int a[5], *ptr_a, small = _INTEGRAL_MAX_BITS;
    for (int i = 0; i < 5; i++)
    {
        printf("a[%d] :  ", i);
        scanf("%d", &a[i]);
    }

    ptr_a = a;
    for (int i = 0; i < 5; i++)
    {
        if (*ptr_a < small)
        {
            small = *ptr_a;
        }
        ptr_a = ptr_a + 1;
    }
    
    printf("small: %d", small);

}