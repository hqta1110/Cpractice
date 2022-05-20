#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int a[], int n)
{
    struct Node *t, *last;
    first = (struct Node*) malloc(sizeof(struct Node));
    first->data = a[0]; 
    first->next=NULL;
    last = first;

    for (int i=1;i<n;i++)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next=t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int count(struct Node *p)
{
    if (p==NULL) return 0;
    else return count(p->next) + 1;
}

int sum(struct Node *p)
{
    if (p==NULL) return 0;
    else return sum(p->next) + p->data;
}

int maximum(struct Node *p)
{
    int max = p->data;
    while(p!=NULL)
    {
        if (p->data>=max) max = p->data;
        p = p->next;
    }
    return max;
}

Node * search(Node *p, int key)
{
    Node *q;
    while (p!=NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p = p->next;
    }
    return NULL;
}

void insert(Node *p,int value, int pos)
{
    Node* b = new Node;
    b->data=value;
    b->next=NULL;
    if (pos==0)
    {
        b->next = first;
        first = b;
    }
    else{
        int count1 = count(p);
        if (pos>count1) pos=count1;
        for (int i=1;i<pos;i++)
        {
            p = p->next;
        }
        b->next = p->next;
        p->next = b;
    }
}

void sortedinsert(Node *p, int value)
{
    Node *q;
    Node *b = new Node;
    b->data = value;
    b->next = NULL;
    while(p!=NULL && p->data<value)
    {
        q=p;
        p = p->next;
    }
    if (p==first)
    {
        b->next = p;
        first = b;
    }
    else{
    b->next = q->next;    
    q->next = b;
     }
}

void del(Node *p, int key)
{
    if (key==1)
    {
        Node *q = first;
        first = first->next;
        delete q;
    }
    else 
    {
        Node *q;
        for (int i=1;i<key;i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        delete p;

    }
}

int check(Node *p)
{
    int x = -9999;
    
    while (p!=NULL)
    {
        if (p->data > x) x= p->data;
        else return 0;
        p = p->next;
    }
    return 1;
}
void reverse1(Node *p)
{
    int arr[10000];
    int i=0;
    while (p!=NULL)
    {
        arr[i++] = p->data;
        p=p->next;
    }
    Node *q = first;
    while (q!=NULL)
    {
        q->data = arr[--i];
        q=q->next;
    }
}
void reverse2(Node *p)
{
    Node *q,*r;
    while (p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;
}
void reverse3(Node *q, Node *p)
{
    if (p!=NULL)
    {
         reverse3(p,p->next);
         p->next = q;
    }
    else{
        first = q;
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
        if (p->next == NULL) first = p;
    }
}
int main()
{
    int a[] = {1,2,3,4,5,6};
    create(a,6);
    display(first);
    printf("\n");
    Node *q = NULL;
    reverse3(q,first);
    display(first);
    return 0;
}