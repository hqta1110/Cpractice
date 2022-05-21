#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node * prev;
    int data;
    struct Node* next;
}*first;
void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;
    for (int i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        t->prev  = last;
        last->next = t;
        last = t;
    }
    
}
void display(struct Node *p)
{
    
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int count(struct Node *p)
{
    if (p==NULL) return 0;
    else return count(p->next) + 1;
}
void insert(struct Node *p,int value, int pos)
{
    struct Node* b =  (struct Node*)malloc(sizeof(struct Node));
    struct Node *q;
    b->data=value;
    b->next=NULL;
    if (pos==0)
    {
        b->next = first;
        b->prev = NULL;
        first->prev = b;
        first = b;
    }
    else{
        int count1 = count(p);
        if (pos>count1) pos=count1;
        for (int i=1;i<pos-1;i++)
        {
            p = p->next;
        }
        b->next = p->next;
        b->prev = p;
        if (p->next)
        {
            p->next->prev = b;
        }
        p->next = b;
        
    }
}
void delete(struct Node *p, int pos)
{
    int length = count(p);
    struct Node *t;
    if (pos<1 || pos > length)
    {
        printf("Index out of range\n");
        return;
    }
    if (pos==1)
    {
        t = first;
        first = first->next;
        t->next = NULL;
        free(t);
        if (first)
        {
            first->prev = NULL;
        }
    }
    else{
        for (int i=1;i<pos;i++) p=p->next;
        p->prev->next = p->next;
        if (p->next) p->next->prev = p->prev;
        free(p);
}
}
void reverse(struct Node *p)
{
    struct Node* temp;
    p = first;
    while (p)
    {
        temp  = p->next;
        p->next = p->prev;
        p->prev = temp;
        p=p->prev;
        if (p!= NULL && p->next == NULL) first = p;
    }
}
int main()
{
    int a[5]= {1,2,3,4,5};
    create(a,5);
    display(first);
    return 0;
}
