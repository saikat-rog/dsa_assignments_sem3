#include<stdio.h>
void main(){
    int a[6] = {98, 12, 58, 3, 63, 20};

    printf("The array before sorting: ");
    for(int i = 0; i < 6; i++){
        printf("%d  ", a[i]);
    }

    for(int i = 0; i < 5; i++){
        for (int j = 0; j < 5-i; j++){
            if (a[j] > a[j+1])
            {
                int temp = a[j+1];
                a[j + 1]= a [j];
                a[j]=temp ;
            }
        }
    }

    printf("The array after sorting: ");
    for(int i = 0; i < 6; i++){
        printf("%d  ", a[i]);
    }
}