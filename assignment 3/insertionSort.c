#include<stdio.h>
void main(){
    int a[6] = {98, 12, 58, 3, 63, 20};

    printf("The array before sorting: ");
    for(int i = 0; i < 6; i++){
        printf("%d  ", a[i]);
    }
    
    for (int i = 1; i < 6; i++)
    {
        int key = a[i];
        int j = i-1;
        while (a[j] > key && j >= 0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    printf("The array after sorting: ");
    for(int i = 0; i < 6; i++){
        printf("%d  ", a[i]);
    }
    
}