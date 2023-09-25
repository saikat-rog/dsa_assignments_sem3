// 13.Write a menu-driven program in C to perform the following operations on string using standard library functions.
// i) Calculate length of string
// ii) Reverse a String
// iii) Concatenation of one string to another
// iv) Copy one string in to another
// v) Compare two string.

#include<stdio.h>
#include<string.h>
void main(){
    char string_one[100], string_two[100], string_three[100];
    printf("Enter string_one : ");
    scanf("%s",&string_one);
    printf("Enter string_two : ");
    scanf("%s",&string_two);
    printf("Enter string_three : ");
    scanf("%s",&string_three);
    printf("Length of the string = %d ",strlen(string_one));
    printf("Reverse of the string = %s ",strrev(string_three));
    strcat(string_one, string_two);
    printf("Concatination of the two string = %s ",string_one);
    strcpy(string_one, string_two);
    printf("After copying string_two to string_one = %s ",string_one);
    if (strcmp(string_one, string_three) == 0)
    {
        printf("string_one and string_three are equal.");
    }
    else{
        printf("string_one and string_three are not equal.");
    }
    
}