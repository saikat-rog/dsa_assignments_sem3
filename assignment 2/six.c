// 6) Write a program to search an element using binary search method
#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

int main(void) {
    int n, a[100], x;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Enter num to search: ");
    scanf("%d", &x);
    int result = binarySearch(a, x, 0, n - 1);
    if (result == -1)
        printf("Not found");
    else
        printf("Element is found at index %d", result);
}