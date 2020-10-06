#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct node
{
    char data[100];
    struct node *next;

} node;

node *tambah(node *);
void cetak(node *);
node *hapus(node *);

int main()
{
    node *HEAD = NULL;
    int n;
main:
    system("cls");
    printf("1. Tambah Data\n");
    printf("2. Lihat Data\n");
    printf("3. Hapus Data\n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan anda: ");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        HEAD = tambah(HEAD);
        goto main;
        break;
    case 2:
        cetak(HEAD);
        getch();
        goto main;
    case 3:
        HEAD = hapus(HEAD);
        goto main;
    default:
        break;
    }

    return 0;
}

node *tambah(node *head)
{

    node *temp;
    char n[100];
    printf("Masukkan data: ");
    scanf("%s", &n);
    temp = (node *)malloc(sizeof(node));
    strcpy(temp->data, n);
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

    return head;
}

void cetak(node *head)
{
    if (head == NULL)
    {
        printf("Isi linked list kosong!!!");
    }
    else
    {
        while (head != NULL)
        {
            printf("%s-> ", head->data);
            head = head->next;
        }
    }
}

node *hapus(node *head)
{

    node *ptr, *preptr;
    ptr = head;
    preptr = ptr;

    if (ptr->next == NULL)
    {
        free(ptr);
        head = NULL;
    }
    else
    {
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }

        preptr->next = NULL;
        free(ptr);
    }

    return head;
}