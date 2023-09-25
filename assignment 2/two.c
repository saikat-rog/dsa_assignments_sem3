// 2) There are two arrays A and B. A content 25 elements whereas B contains 30 elements write a function to create an array C that contain only those elements that are common to A and B.
#include<stdio.h>
int main(){
    int a[5], b[7], c[7], c_index = 0;
    printf("Enter array A: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    
    printf("Enter array B: ");
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 7; j++){
            if (a[i] == b[j]){
                c[c_index] = a[i];
                c_index++;
            }
        }
    }

    printf("Array C having common elements: ");
    for (int i = 0; i < c_index; i++)
    {
        printf("%d ", c[i]);
    }
}