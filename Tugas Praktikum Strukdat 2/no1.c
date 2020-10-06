#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;

} node;

node *single(node *);
void cetak(node *);
node *dua(node *);

int main()
{
    node *head = NULL;

    head = single(head);
    // head = dua(head);
    cetak(head);
    return 0;
}

node *single(node *head)
{

    node *temp;
    int n;
    printf("Masukkan data: ");
    while ((scanf("%d", &n)) != EOF)
    {
        temp = (node *)malloc(sizeof(node));
        temp->data = n;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    return head;
}

void cetak(node *head)
{
    while (head != NULL)
    {
        printf("%d-> ", head->data);
        head = head->next;
    }
}

node *dua(node *head)
{
    node *temp;
    int n;
    printf("Masukkan data: ");
    while ((scanf("%d", &n)) != EOF)
    {
        temp = (node *)malloc(sizeof(node));
        temp->data = n;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    return head;
}
