#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    char data[100];
} stack;

stack tumpuk;
void push();
void cetak();
int main()
{
    tumpuk.top = -1;
    char val[100];
    printf("Masukkan kalimat: ");
    fflush(stdin);
    gets(val);
    push(val);
    cetak();
    return 0;
}

void push(char n[100])
{
    int c = 0;
    while (n[c] != '\0')
    {
        tumpuk.top++;
        tumpuk.data[tumpuk.top] = n[c];
        c++;
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
            printf("%c", tumpuk.data[i]);
        }
    }
}
