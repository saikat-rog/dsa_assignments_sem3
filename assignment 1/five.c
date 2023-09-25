// 5. Write a program using array in which find maximum and second maximum number. 

#include <stdio.h>
void main()
{
    int a[5], count = 0, max, sec_max;
    for (int i = 0; i < 5; i++){
        printf("a[%d] :  ", i);
        scanf("%d", &a[i]);
    }

    max = a[0];
    for (int i = 0; i < 5; i++){
        if (max < a[i]){
            sec_max = max;
            max = a[i];
        }
    }

    printf("Max: %d", max);
    printf("Second max: %d\n", sec_max);
    
}