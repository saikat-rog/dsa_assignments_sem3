// Write a program to implement quick sort algorithm
#include<stdio.h>
int main(){
    int a[100];
    int n,i,j,temp;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Sorted array by quick sort: \n");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}