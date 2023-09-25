// 9. Write a 'C' program to swap the values of two variables by using pointers (call by reference).
#include<stdio.h>
void main(){
   int a, b, *ptr_a, *ptr_b, temp;
   printf("Enter a: ");
   scanf("%d", &a);
   printf("Enter b: ");
   scanf("%d", &b);
   ptr_a = &a;
   ptr_b = &b;

   temp = *ptr_a;
   *ptr_a = *ptr_b;
   *ptr_b = temp;
   printf("a = %d and b = %d", a, b);
}