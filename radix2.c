#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
struct node
{
    int data;
    struct node *next;
};
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}
struct node *insert_at_end(struct node *head, int val)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    struct node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new_node;
    return head;
}
void display_array(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}
int *radix_sort(int *ptr, int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] > max)
        {
            max = ptr[i];
        }
    }
    int d = 0;
    int temp = max;
    while (temp != 0)
    {
        d++;
        temp = temp / 10;
    }
    int temp_array[size];
    for (int i = 0; i < size; i++)
    {
        temp_array[i] = ptr[i];
    }
    for (int i = 0; i < d; i++)
    {
        struct node *index[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
        int brr[size];
        for (int q = 0; q < size; q++)
        {
            brr[q] = 0;
        }
        int t = pow(10, i + 1);
        for (int j = 0; j < size; j++)
        {
            int digit = (temp_array[j]) % t;
            if (i != 0)
            {
                digit = digit / (pow(10, i));
            }
            index[digit] = insert_at_end(index[digit], temp_array[j]);
        }
        int k = 0;
        for (int j = 0; j < 10; j++)
        {
            if (index[j] != NULL)
            {
                struct node *tmp = index[j];
                while (tmp != NULL)
                {
                    brr[k] = tmp->data;
                    tmp = tmp->next;
                    k++;
                }
            }
        }
        for (int j = 0; j < size; j++)
        {
            temp_array[j] = brr[j];
        }
        for (int j = 0; j < size; j++)
        {
            ptr[j] = brr[j];
        }
    }
    return ptr;
}
int *reverse_n_array(int *ntr, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(&ntr[i], &ntr[(size - 1) - i]);
    }
    return ntr;
}
void merge(int arr[], int *ptr, int *ntr, int p, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        arr[k] = ntr[i];
        k++;
    }
    for (int i = 0; i < p; i++)
    {
        arr[k] = ptr[i];
        k++;
    }
}
int main()
{
    int org_size;
    printf("Enter the size of the array: ");
    scanf("%d", &org_size);
    int arr[org_size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < org_size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Original Array: ");
    for (int i = 0; i < org_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int n_count = 0;
    for (int i = 0; i < org_size; i++)
    {
        if (arr[i] < 0)
        {
            n_count++;
        }
    }
    int *ntr = (int *)malloc(n_count * sizeof(int));
    int p = 0;
    for (int i = 0; i < org_size; i++)
    {
        if (arr[i] < 0)
        {
            ntr[p] = arr[i];
            p++;
        }
    }
    int p_count = org_size - n_count;
    int *ptr = (int *)malloc(p_count * sizeof(int));
    int q = 0;
    for (int i = 0; i < org_size; i++)
    {
        if (arr[i] >= 0)
        {
            ptr[q] = arr[i];
            q++;
        }
    }

    ptr = radix_sort(ptr, p_count);

    for (int i = 0; i < n_count; i++)
    {
        ntr[i] = -1 * ntr[i];
    }

    ntr = radix_sort(ntr, n_count);
    ntr = reverse_n_array(ntr, n_count);
    for (int i = 0; i < n_count; i++)
    {
        ntr[i] = -1 * ntr[i];
    }

    merge(arr, ptr, ntr, p_count, n_count);
    printf("Array after modified radix sort: ");
    for (int i = 0; i < org_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}