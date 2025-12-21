#include <stdio.h>
#include <stdlib.h>
#include "double_linked.h"

Node_t* node_init(int data)
{
    Node_t *new_node = malloc(sizeof(Node_t));
    if (NULL == new_node)
    {
        printf("NODE_INIT: Allocation failed");
        return NULL;
    }

    new_node->data = data;
    new_node->previous = NULL;
    new_node->next = NULL;
    return new_node;
}

void prepend_list_int(Node_t** head, int data)
{
    if (NULL != *head)
    {
        Node_t* current_node = *head;
        current_node->previous = node_init(data);
        current_node->previous->next = current_node;
        *head = current_node->previous;
    }
    else
    {
        *head = node_init(data);
    }
}

void append_list_int(Node_t** head, int data)
{
    if (NULL != *head)
    {
        Node_t* current_node = *head;
        while (NULL != current_node->next)
        {
            current_node = current_node->next;
        }

        current_node->next = node_init(data);
        current_node->next->previous = current_node;
    }
    else
    {
        printf("APPEND_LIST: List is empty. Initializing.\n");
        *head = node_init(data);
    }
}

void insert_node(Node_t** head, uint32 position, int data)
{
    if (NULL != *head)
    {
        Node_t* current_node = *head;
        uint32 steps = 0u;
        for (steps = 0; ((steps < position) && (NULL != current_node->next)); ++steps)
        {
            current_node = current_node->next;
        }

        Node_t *new_node = node_init(data);
        if ((position - steps) >= 1u) /* We are going outside of the list range, so we are appending. */
        {
            current_node->next = new_node;
            new_node->previous = current_node;
            return;
        }

        if (NULL == current_node->previous) /* Insert at the beginning of the list. */
        {
            new_node->next = current_node;
            current_node->previous = new_node;
            *head = new_node;
        }
        else 
        {
            new_node->previous = current_node->previous;
            new_node->next = current_node;
            current_node->previous->next = new_node;
            current_node->previous = new_node;
        }
    }
    else
    {
        printf("INSERT_NODE: List is empty. Initializing.\n");
        *head = node_init(data);
        return;
    }
}

void delete_node(Node_t** head, uint32 node_number)
{
    if (NULL != *head)
    {
        Node_t* current_node = *head;
        for (uint32 i = 0; (i < node_number) && (NULL != current_node); ++i)
        {
            current_node = current_node->next;
        }

        if (NULL == current_node)
        {
            printf("DELETE_NODE: Invalid node number\n");
            return;
        }

        if (NULL == current_node->previous)
        {
            *head = current_node->next;
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
}

void display_list(Node_t* head)
{
    if (NULL != head)
    {
        int i = 0;
        Node_t *current_node = head;
        while (NULL != current_node)
        {
            printf("Node %d data: %d\n", i, current_node->data);
            current_node = current_node->next;
            i++;
        }
    }
    else
    {
        printf("DISPLAY_LIST: List is empty.\n");
    }
}

void free_list(Node_t** head)
{
    if (NULL != *head)
    {
        Node_t* current_node = *head;
        while(NULL != current_node->next)
        {
            Node_t* temp_node = current_node->next;
            free(current_node);
            current_node = temp_node;
        }
        free(current_node);
        *head = NULL;
    }
}