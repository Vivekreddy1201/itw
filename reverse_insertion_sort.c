#include <stdio.h>
#include<time.h>
void reverseInsertionSort(int arr[], int n) {
    int i, key, j;
    for (i = n - 2; i >= 0; i--) {
        key = arr[i];
        j = i + 1;
        while (j < n && arr[j] > key) {
            arr[j - 1] = arr[j];
            j = j + 1;
        }
        arr[j - 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++)
        printf("%d\n ", arr[i]);

    reverseInsertionSort(arr, n);

    printf("Sorted array in reverse order: \n");
     for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
        time_t currentTime;
time(&currentTime);
struct tm *localTime = localtime(&currentTime);
printf("Name: M.Vivek Reddy\n");
printf("Roll No: BT23CSE048\n");
printf("Current local time: %s", asctime(localTime));
    return 0;
}
