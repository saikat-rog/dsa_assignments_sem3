// Write a program (using recursion) to check whether a number is armstrong or not?(Input given by the user)
#include <stdio.h>
#include <math.h>

int checkArmstrong(int num){
    if (num>0)
    {
        return (pow(num%10, 3)+ checkArmstrong(num/10));
    }
    
}

void main()
{
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    if (checkArmstrong(num) == num)
    {
        printf("Armstrong number");
    }
    else
    {
        printf("Not an armstrong number.");
        
    }

}