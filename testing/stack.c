#include <stdio.h>
#include <stdlib.h>
#define MS 5
typedef struct
{
    int arr[MS];
    int top;
} stack;
void init(stack *s)
{
    s->top = -1;
}
void push(stack *s, int x)
{
    if (s->top == MS - 1)
    {
        printf("stack overflow ho raha hai");
        return;
    }
    s->top++;
    s->arr[s->top] = x;
}
void pop(stack *s)
{
    if (s->top == -1)
    {
        printf("stack underflow hai");
        return;
    }
    s->top -= 1;
}
int getsize(stack *s)
{
    int size = s->top + 1;
    return size;
}
void display(stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d", s->arr[i]);
    }
    printf("\n");
}
int main()
{
    stack s;
    init(&s);
    push(&s, 10);
    display(&s);
    push(&s, 20);
    display(&s);
    push(&s, 30);
    display(&s);
    push(&s, 40);
    display(&s);
    push(&s, 50);
    display(&s);
    printf("The size --->%d\n", getsize(&s));
    pop(&s);
    pop(&s);
    pop(&s);
    display(&s);
}