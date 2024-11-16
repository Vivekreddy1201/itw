#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row;
    int col;
    int value;
    struct node *next;
} head;
int arr[4][5] =
    {
        {0, 2, 3, 0, 4},
        {0, 1, 5, 7, 0},
        {0, 8, 0, 0, 0},
        {7, 2, 6, 0, 0}};

struct node *create(int r, int c, int v)
{
    struct node *t = malloc(sizeof(struct node));
    t->row = r;
    t->col = c;
    t->value = v;
    t->next = NULL;
    return t;
}
void check(struct node **head)
{
    struct node *current = NULL;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] != 0)
            {
                struct node *new_node = create(i, j, arr[i][j]);
                if (*head == NULL)
                {
                    *head = new_node;
                    current = *head;
                }
                else
                {
                    current->next = new_node;
                    current = new_node;
                }
            }
        }
    }
}

void display(struct node *head)
{
    struct node *t;
    t = head;
    printf("row  coloum  value\n");
    while (t != NULL)
    {
        printf("%d", t->row);
        printf("%d", t->col);
        printf("%d\n", t->value);
        t = t->next;
    }
}
int main()
{
    struct node *head = NULL;
    check(&head);
    display(head);
}