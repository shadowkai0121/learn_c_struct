/**
 * struct 應用
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct node_t node_t;
struct node_t
{
    int data;
    node_t * next;
};

typedef struct stack_t stack_t;
struct stack_t
{
    node_t * top;
};

stack_t * create_stack();
int insert_data(stack_t * st, int data);
int free_stack(stack_t * st);
int pop_stack(stack_t * st);

stack_t * create_stack()
{
    return malloc(sizeof(stack_t));
}

int pop_stack(stack_t * st)
{
    node_t * node = st->top;
    if (node) {
        st->top = node->next;
        int data = node->data;
        free(node);
        return data;
    }
    return 0;
}

int insert_data(stack_t * st, int data)
{
    node_t * node = malloc(sizeof(node_t));
    if (!node) {
        free_stack(st);
        return 1;
    }
    node->data = data;
    node->next = st->top;
    st->top = node;
    return 0;
}

int free_stack(stack_t * st)
{
    node_t *cur = st->top;
    node_t *tmp;
    while (cur)
    {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(st);
    return 0;
}

int main(int argc, char const *argv[])
{
    stack_t * st = create_stack();
    insert_data(st, 1);
    insert_data(st, 11);
    int data = pop_stack(st);
    printf("%d\n", data);
    data = pop_stack(st);
    printf("%d\n", data);
    free_stack(st);
    return 0;
}

