#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct linked_list List;

struct node
{
    struct node* next;
    int value;
};

Node* new_node(int value)
{
    Node* v = malloc(sizeof(Node));
    v->next = NULL;
    v->value = value;
    return v;
}

struct linked_list
{
    Node* head;
    size_t size;
};

void insert_node(List *arr, int pos, Node* new_node)
{
    if(pos > arr->size || pos < 0)
        return;
    if(pos == 0)
    {
        new_node->next = arr->head;
        arr->head = new_node;
        ++arr->size;
        return;
    }
    Node* start = arr->head;
    while(--pos)
        start = start->next;
    new_node->next = start->next;
    start->next = new_node;
    ++arr->size;
}

void remove_node(List *arr, int pos)
{
    if(pos > arr->size || pos < 0)
        return;
    if(pos == 0)
    {
        Node *tmp = arr->head->next;
        free(arr->head);
        arr->head = tmp;
        --arr->size;
        return;
    }
    Node* start = arr->head;
    while(--pos)
        start = start->next;
    Node *tmp = start->next->next;
    free(start->next);
    start->next = tmp;
    --arr->size;
}

void print_list(List *arr)
{
    for(Node* p = arr->head; p != NULL; p = p->next)
        printf("%d ", p->value);
}

void erase(List *arr)
{
    printf("hewwo");
    Node *tmp = NULL;
    for(Node* p = arr->head; p != NULL; p = tmp)
    {
        tmp = p->next;
        free(p);
    }
    free(tmp);
}

void init(List *arr)
{
    arr->head = NULL;
    arr->size = 0;
}

int main () {
    List test; // 0-indexing
    init(&test); // constructor
    int n = 5;
    insert_node(&test, 0, new_node(n)); // insert at 0
    n = 3;
    insert_node(&test, 0, new_node(n));
    n = 2;
    insert_node(&test, 1, new_node(n)); // insert at 1
    print_list(&test); //prints 3 2 5
    printf("\n");
    remove_node(&test, 1); // remove at 1
    print_list(&test); //prints 3 5
    erase(&test); // free memory
    return 0;
}