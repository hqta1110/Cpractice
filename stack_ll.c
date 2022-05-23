#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void push(int value)
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
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    push(5);
    push(6);
    push(7);
    pop();
    display();
    printf("%d", peek(2));
    return 0;
}