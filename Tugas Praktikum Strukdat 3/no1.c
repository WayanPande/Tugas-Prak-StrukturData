#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 5

typedef struct stack
{
    int top;
    char data[100][100];
} stack;

void push();
void pop();
void cetak();
stack tumpuk;
int main()
{
    int option;
    char val[100];
    tumpuk.top = -1;
main:
    system("cls");
    printf("\n *****MAIN MENU*****");
    printf("\n 1. PUSH");
    printf("\n 2. POP");
    printf("\n 3. DISPLAY");
    printf("\n 4. EXIT");
    printf("\n Enter your option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("Enter the number to be pushed on stack: ");
        fflush(stdin);
        gets(val);
        push(val);
        goto main;
        break;
    case 2:
        pop();
        goto main;
        break;
    case 3:
        cetak();
        getch();
        goto main;
        break;
    default:
        break;
    }
    return 0;
}

void push(char n[100])
{
    if (tumpuk.top == 4)
    {
        printf("Stack Penuh");
        getch();
    }
    else
    {
        tumpuk.top++;
        strcpy(tumpuk.data[tumpuk.top], n);
    }
}

void pop()
{
    if (tumpuk.top == -1)
    {
        printf("Stack Kosong");
    }
    else
    {
        tumpuk.top--;
        printf("Data berhasil di pop");
    }
}

void cetak()
{
    if (tumpuk.top == -1)
    {
        printf("Stack kosong");
    }
    else
    {
        for (int i = tumpuk.top; i >= 0; i--)
        {
            printf("%s\n", tumpuk.data[i]);
        }
    }
}
