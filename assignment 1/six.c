// 6. Write a program to insert the new element in array at given location k

#include<stdio.h>
void main(){
    int a[100],k,num, n = 5;
    for (int i = 0; i < n; i++){
        printf("a[%d] :  ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter element: ");
    scanf("%d", &num);
    printf("Enter location: \n");
    scanf("%d", &k);

    for (int i = 0; i < n; i++){
        if (i == k){
            for (int i = n+1; i > k; i--){
                a[i] = a[i-1];
            }
            a[k] = num;
        }
    }

    printf("New array: ");
    for (int i = 0; i < n+1; i++){
        printf("%d ", a[i]);
    }  
}