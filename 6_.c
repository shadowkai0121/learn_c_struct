/**
 * Stack
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t node_t; // 在 struct 之後定義會無法使用 pointer 成員
struct node_t
{
    int data;
    node_t *next;
};

typedef struct stack_t stack_t;
struct stack_t
{
    node_t *top;
};

int main(int argc, char const *argv[])
{
    // bool failed = false;
    stack_t *st = malloc(sizeof(stack_t));

    // insert an node
    {
        node_t *node = malloc(sizeof(node_t));
        if (!node) {
            perror("memory allocate error");
            // failed = true;
            goto FREE_STACK;
        }
        node->data = 9;
        node->next = NULL;
        
        st->top = node;
    }

    do
    {
        node_t *cur = st->top;
        if (!cur) {
            break;
        }
        printf("%d\n", cur->data);
        st->top = cur->next;
        free(cur);
    } while (true);
    

FREE_STACK:
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
        
    }
    return 0;
}

