#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *insert_at_end(struct Node *head, int val)
{
    struct Node *newnode = (struct Node *)(malloc(sizeof(struct Node)));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int max = INT_MIN;
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i]; // to find the largest number
        }
    }
    int digits = 0;
    int temp = max;
    while (temp)
    {
        digits++;
        temp = temp / 10;
    }
    int temp_array[n];
    for (int i = 0; i < n; i++)
    {
        temp_array[i] = arr[i];
    }
    for (int i = 0; i < digits; i++)
    {
        struct Node *bucket[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

        int B[n];
        for (int q = 0; q < n; q++)
        {
            B[q] = 0;
        }
        int t = pow(10, i + 1);
        for (int j = 0; j < n; j++)
        {
            int a = temp_array[j] % t;
            if (i != 0)
            {
                a = a / (pow(10, i));
            }
            bucket[a] = insert_at_end(bucket[a], temp_array[j]);
        }
        int p = 0;
        for (int k = 0; k < 10; k++)
        {
            if (bucket[k] != NULL)
            {
                struct Node *temp = bucket[k];
                while (temp != NULL)
                {
                    B[p] = temp->data;
                    p++;
                    temp = temp->next;
                }
            }
        }
        for (int q = 0; q < n; q++)
        {
            temp_array[q] = B[q];
        }
        for (int k = 0; k < n; k++)
        {
            arr[k] = B[k];
        }
    }
    printf("Array after radix sort: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}