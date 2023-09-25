// 7. Write a program to search the location of a given element in array and after searching delete that element from array.

#include <stdio.h>
void main()
{
    int a[10], location, num;
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] :  ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter element: ");
    scanf("%d", &num);

    for (int i = 0; i < 10; i++)
    {
        if (a[i] == num)
        {
            location = i;
            for (int i = location; i < 9; i++)
            {
                a[i] = a[i + 1];
            }
        }
    }

    printf("The location was: %d\n", location);
    printf("The array after deleting: ");
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }
}