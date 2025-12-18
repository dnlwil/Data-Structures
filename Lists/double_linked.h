#ifndef DOUBLE_LINKED_H
#define DOUBLE_LINKED_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct Node
{
    int data;
    struct Node *previous;
    struct Node *next;
} Node;

Node* node_init(Node*, int data);
void append_list_int(Node** head, int data);
Node* delete_node(Node* head, uint32 node_number);
void display_list(Node* head);

#endif