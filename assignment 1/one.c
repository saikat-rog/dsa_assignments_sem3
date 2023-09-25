// 1. Write a program to check whether a number is armstrong or not?(Input given by the user)
#include <stdio.h>
#include <math.h>
void main()
{
    int num, temp, temp1, sum = 0, num_of_digits = 0;
    printf("Enter the number: ");
    scanf("%d", &num);
    temp = num, temp1 = num;
    while (temp1!= 0)
    {
        temp1 = temp1 / 10;
        num_of_digits++;
    }
    
    while (temp != 0)
    {
        int rem = temp % 10;
        sum = sum + pow(rem, num_of_digits);
        temp = temp / 10;
    }
    if (sum == num)
    {
        printf("Armstrong number");
    }
    else
    {
        printf("Not an armstrong number");
    }
}