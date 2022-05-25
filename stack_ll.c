#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char data;
    struct Node *next;
}*top = NULL;

void push(char value)
{
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    if (t)
    {
        t->data = value;
        t->next = top;
        top = t;
    }
    else{
        printf("Stack is full\n");
    }
}
void pop()
{
    if (top)
    {
        struct Node *t = top;
        top = top->next;
        free(t);
    }
    else printf("Stack is empty\n");
}
int peek(int pos)
{
    struct Node *p = top;
    for (int i = 0;p!=NULL && i<pos-1;i++)
    {
        p = p->next;
    }
    if (p) return p->data;
    else return -99999;
}
int isEmpty()
{
    return (top==NULL);
}
void display()
{
    struct Node *p = top;
    while (p!=NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}
int isValid(char *exp)
{
    for (int i=0;i<strlen(exp);i++)
    {
        if (exp[i]=='(') push(exp[i]);
        else if (exp[i]==')')
        {
            if (isEmpty()) return 0;
            pop();
        }
    }
    return isEmpty()?1:0;
}
int main()
{
    
    char exp[100] = "((a+b))((c+d))";
    printf("%d", isValid(exp));
    return 0;
}