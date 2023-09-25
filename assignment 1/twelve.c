// 12.Write a C program to check whether the entered character is digit or an alphabet.

#include <stdio.h>
void main()
{
    char cha;
    int ascii;
    printf("Enter the char: ");
    scanf("%c", &cha);
    ascii = (int)cha;
    if (ascii >= 48 && ascii <= 57)
    {
        printf("Entered char is digit.");
    }
    else{
        printf("Entered char is alphabet.");
    }
    
}