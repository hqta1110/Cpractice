#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
}*head;

void create(int a[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node*) malloc(sizeof(struct  Node));
    head->data = a[0];
    head->next = head;
    last = head;
    for (int i=1;i<n;i++)
    {
        t = (struct Node*) malloc(sizeof(struct  Node));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void display(struct Node* p)
{
    do {
        printf("%d ", p->data);
        p = p->next;
    }
    while (p!=head);
    printf("\n");
}
void insert(int pos, int value)
{
    struct Node *t, *p;
    int i;
    t = (struct Node*) malloc(sizeof(struct Node));
    t->data = value;    
    if (pos==0)
    {

        if (head == NULL)
        {
            head = t;
            head ->next = head;
        }
        else{
            p = head;
            while (p->next != head) p=p->next;
            p->next = t;
            t ->next = head;
            head = t;
        }
    }
    else{
        p = head;
        for (int i =0;i<pos-1;i++) p=p->next;
        t->next = p->next;
        p->next = t;

    }
}
void del(int pos)
{
    struct Node *p, *q;
    p=head;
    if (pos==1)
    {
        while(p->next!=head)
        {
            p=p->next;
        }
        if (p==head)
        {
            free(p);
            head = NULL;
        }
        else 
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (int i=0;i<pos-2;i++) p=p->next;
        q = p->next;
        p->next = q->next;
        free(q);
    }
}
int main()
{
    int a[] = {1,2,4,4,5};
    create(a,5);
    display(head);
    del(6);
    display(head);
    return 0;
}