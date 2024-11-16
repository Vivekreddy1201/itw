#include <stdio.h>
#include<time.h>
void reverseSelectionSort(int arr[], int n) {
    int i, j, max;
    for (i = n - 1; i > 0; i--) {
        max= i;
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
   for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    reverseSelectionSort(arr, n);

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
