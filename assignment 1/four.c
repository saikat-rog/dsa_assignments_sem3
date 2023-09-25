// 4. Twenty five numbers are entered from the keyboard into an array. The number to be searched is entered through the keyboard by the user. Write a program to find if the number to be searched is present in the array and if it is present, display the number of times it appears in the array.

#include <stdio.h>
void main()
{
    int num, a[5], count = 0;
    for (int i = 0; i < 5; i++){
        printf("a[%d] :  ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter the num to search: ");
    scanf("%d", &num);

    for (int i = 0; i < 5; i++){
        if (num == a[i]){
            count++;
        }
    }

    if (count > 0){
        printf("%d appears %d time.", num, count);
    }
    else{
        printf("%d is not present.", num);
    }
    
}