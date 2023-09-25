// 3. Write a program to print the following sequence of numbers:  0,1,1,2,3,5,8,13,21,34...

#include<stdio.h>
void main(){
    int num1 = 0, num2 = 1;
    printf("%d ", num1);
    printf("%d ", num1+num2);
    for (int i = 0; i < 50; i++){
        int sum = num1+num2;
        printf("%d ", sum);
        num1 = num2;
        num2 = sum;
    }
   
}