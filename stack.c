#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
    int size;
    int top;
    char *s;
};
void create(struct Stack *st)
{
    printf("Enter size of stack:\n");
    scanf("%d", &st->size);
    st->s  = (char *) malloc(sizeof(char)*st->size);
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
        printf("%c ", st.s[i]);
    }
    printf("\n");
}
void push(struct Stack *st, char value)
{
    if (!isFull(*st))
    {
        st->top++;
        st->s[st->top] = value;
    }
    else printf("Stack is full\n");
}
char pop(struct Stack *st)
{
    char x;
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
int isValid(char *exp)
{
    struct Stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.s  = (char *) malloc(sizeof(char)*st.size);
    char x,y;
    for (int i=0;exp[i]!='\0';i++)
    {
        if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{') push(&st, exp[i]);
        else if (exp[i]==')'|| exp[i]==']'|| exp[i]=='}')
        {
            if (isEmpty(st)) return 0;
            else{
                x = pop(&st);
                y = exp[i];
                if ((x=='(' && y==')') || (x=='[' && y==']') || (x=='{'&& y=='}')) continue;
                else return 0;
            }
        }
    }
    return isEmpty(st)?1:0;
}

int main()
{   //initalize
    char exp[100]="([}*))";
    printf("%d",isValid(exp));
    return 0;
}