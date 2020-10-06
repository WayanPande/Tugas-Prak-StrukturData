#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;

} node;

node *dua(node *);
void cetak(node *);

int main()
{
    node *head = NULL;

    head = dua(head);
    cetak(head);
    return 0;
}

node *dua(node *head)
{
    node *temp, *tail;
    int n;
    printf("Masukkan data: ");
    while ((scanf("%d", &n)) != EOF)
    {
        temp = (node *)malloc(sizeof(node));
        temp->data = n;
        temp->next = temp->prev = temp;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            tail = head->prev;
            temp->next = head;
            head->prev = temp;
            temp->prev = tail;
            tail->next = temp;
        }
    }

    return head;
}

void cetak(node *head)
{
    node *temp = head;

    do
    {
        printf("%d-> ", head->data);
        head = head->next;
    } while (head != temp);
}