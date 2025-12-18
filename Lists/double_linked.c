#include <stdio.h>
#include <stdlib.h>
#include "double_linked.h"

Node* node_init(Node* node, int data)
{
    if(NULL == node)
    {
        Node *new_node = malloc(sizeof(Node));
        new_node->data = data;
        new_node->previous = NULL;
        new_node->next = NULL;
        return new_node;
    }
    else
    {
        printf("Node already initialized.\n");
        return node;
    }
}

void prepend_list_int(Node** head, int data)
{
    if (NULL != *head)
    {
        Node* current_node = *head;
        current_node->previous = node_init(current_node->previous, data);
        current_node->previous->next = current_node;
        *head = current_node->previous;
    }
    else
    {
        *head = node_init(*head, data);
    }
}

void append_list_int(Node** head, int data)
{
    if (NULL != *head)
    {
        Node* current_node = *head;
        while (NULL != current_node->next)
        {
            current_node = current_node->next;
        }
            current_node->next = node_init(current_node->next, data);
            current_node->next->previous = current_node;
    }
    else
    {
        *head = node_init(*head, data);
    }
}

Node* delete_node(Node* head, uint32 node_number)
{
    if (NULL != head)
    {
        Node* current_node = head;
        for (uint32 i=0;i<node_number && NULL != current_node;++i)
        {
            current_node = current_node->next;
        }

        if (NULL == current_node)
        {
            printf("DELETE_NODE: Invalid node number\n");
            return head;
        }

        if (NULL == current_node->previous)
        {
            head = current_node->next;
            if (NULL != current_node->next)
            {
                current_node->next->previous = NULL;
            }
        }
        else /* NULL != current_node->previous */
        {
            current_node->previous->next = current_node->next;
        }

        if (NULL != current_node->next)
        {
            current_node->next->previous = current_node->previous;
        }

        free(current_node);
    }
    else
    {
        printf("DELETE_NODE: Provided list is empty.\n");
    }

    return head;
}

void display_list(Node* head)
{
    if (NULL != head)
    {
        int i = 0;
        Node *current_node = head;
        while (NULL != current_node)
        {
            printf("Node %d data: %d\n", i, current_node->data);
            current_node = current_node->next;
            i++;
        }
    }
    else
    {
        printf("List is empty.\n");
    }
}