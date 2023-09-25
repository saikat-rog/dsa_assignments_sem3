// 5) Tighter program to implement linear search
#include <stdio.h>

int main() {
    int n, a[100], x;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Enter num to search: ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++){
        if (a[i] == x){
            printf("Element found at index: %d", i);
            break;
        }
        else{
            printf("Element not found");
        }
    }
}