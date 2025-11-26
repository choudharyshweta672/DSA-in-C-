#include<stdio.h>

int binarySearch(int arr[], int size, int key){
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1; // target is in right half
        } else {
            high = mid - 1; // target is in left half
        }
    }
    return -1; // element not found
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr) / sizeof(arr[0]);
     int key;
    //printf("elements to be searched:\n");
   
    //scanf("%d\n",&key);
   

    int index = binarySearch(arr, size, key);
    if (index != -1)
        printf("element found at index %d\n", index);
    else
        printf("element not found\n");

    return 0;
}