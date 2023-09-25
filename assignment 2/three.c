// 3) Write a menu program for following string operation.
//     - Two strings are equal or not
//     - First string is smaller to second string
//     - First string is greater to second strings
//     - Extract left most n th character
//     - Extract right most n th character
#include<stdio.h>
#include<string.h>
void main(){
    int choice, lmn, rmn;char str1[20], str2[20];
    printf("1) Two Strings are equal or not. 2) First String is smaller to second string 3) First string is greater to second string 4) Extract left most n char. 5) Extract right most n char\nEnter your choice: ");
    scanf("%d",&choice);
    printf("Enter string1: ");
    scanf("%s", str1);
    
    switch (choice)
    {
    case 1:
        printf("Enter string2: ");
        scanf("%s", str2);
        if ((strcmp(str1, str2)) == 0){
            printf("The strings are equal.");
        }
        else{
            printf("The strings are not equal.");
        }
        break;

    case 2:
        printf("Enter string2: ");
        scanf("%s", str2);
        if (strcmp(str1, str2) < 0){
            printf("First String is smaller to second string.");
        }
        
        break;

    case 3:
        printf("Enter string2: ");
        scanf("%s", str2);
        if (strcmp(str1, str2) > 0){
            printf("First String is greater to second string.");
        }
        break;

    case 4:
        printf("Enter position of left most n: ");
        scanf("%d", &lmn);
        printf("The left most %dth char is: %c", lmn, str1[lmn-1]);
        break;
    
    case 5:
        printf("Enter position of right most n: ");
        scanf("%d", &rmn);
        printf("The right most %dth char is: %c", rmn, str1[(strlen(str1))-rmn]);
        break;

    default:
        printf("Enter correct choice.");
    }


}