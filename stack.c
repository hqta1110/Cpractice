#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *s;
};
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
    for (int i=0;i<=st.top;i++)
    {
        printf("%d ", st.s[i]);
    }
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
void pop(struct Stack *st)
{
    if (!isEmpty(*st))
    {
        st->top--;
    }
    else printf("Stack is empty\n");
}
int main()
{   //initalize
    struct Stack st;
    printf("Enter size of stack:\n");
    scanf("%d", &st.size);
    st.s  = (int *) malloc(sizeof(int)*st.size);
    st.top = -1;
    push(&st, 5);
    push(&st, 7);
    pop(&st);
    display(st);

    
    return 0;
}