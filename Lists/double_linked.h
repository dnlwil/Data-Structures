#ifndef DOUBLE_LINKED_H
#define DOUBLE_LINKED_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct Node_t
{
    int data;
    struct Node_t *previous;
    struct Node_t *next;
} Node_t;

Node_t* node_init(int data);
void prepend_list_int(Node_t** head, int data);
void append_list_int(Node_t** head, int data);
void insert_node(Node_t** head, uint32 position, int data);
Node_t* delete_node(Node_t* head, uint32 node_number);
void display_list(Node_t* head);
void free_list(Node_t** head);

#endif