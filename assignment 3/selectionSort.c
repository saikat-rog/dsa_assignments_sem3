#include<stdio.h>
int main(){
    int a[6] = {98, 12, 58, 3, 63, 20};

    printf("The array before sorting: ");
    for(int i = 0; i < 6; i++){
        printf("%d  ", a[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 6; j++)
        {
            if (a[j] < a[i])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nThe array after sorting: ");
    for(int i = 0; i < 6; i++){
        printf("%d  ", a[i]);
    }
    
}