#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *s;
};
void create(struct Stack *st)
{
    printf("Enter size of stack:\n");
    scanf("%d", &st->size);
    st->s  = (int *) malloc(sizeof(int)*st->size);
    st->top = -1;
}
int isFull(struct Stack st)
{
    if (st.top == st.size -1) return 1;
    return 0; 
}
int isEmpty(struct Stack st)
{
    if (st.top == -1) return 1;
    return 0;
}
void display(struct Stack st)
{
    for (int i=st.top;i>=0;i--)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}
void push(struct Stack *st, int value)
{
    if (!isFull(*st))
    {
        st->top++;
        st->s[st->top] = value;
    }
    else printf("Stack is full\n");
}
int pop(struct Stack *st)
{
    int x=-9999;
    if (!isEmpty(*st))
    {
        x = st->s[st->top--];
    }
    else printf("Stack is empty\n");
    return x;
}
int peek(struct Stack st, int pos)
{
    if (st.top == -1) return -99999;
    if (st.top - pos + 1 < 0 || st.top - pos + 1 > st.top) return -9999;
    else return st.s[st.top - pos +1];
}
int main()
{   //initalize
    struct Stack st;
    create(&st);
    push(&st, 5);
    pop(&st);
    pop(&st);
    display(st);
    printf("%d", peek(st, 0));

    
    return 0;
}