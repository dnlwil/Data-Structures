#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_linked.h"

int main()
{
    uint8 choice = 0;
    char buf[10] = {'\0'};
    char *endptr = NULL;
    uint8 exit = 0;

    Node *head = NULL;
    while(0 == exit)
    {
        printf("1 - Init List\n2 - Prepend list\n3 - Append list\n4 - Delete element\n5 - Display list\n9 - Exit\n");
        fgets(buf,sizeof(buf),stdin);
        choice = atoi(buf);
        switch(choice)
        {
            case 1: 
                printf("Provide value for initialization: ");
                fgets(buf,sizeof(buf),stdin);
                head = node_init(head, (int)atoi(buf)); 
                break;
            case 2:
                printf("Provide value to prepend with: ");
                fgets(buf,sizeof(buf),stdin);
                prepend_list_int(&head, (int)atoi(buf));
                break;
            case 3:
                printf("Provide value to append with: ");
                fgets(buf,sizeof(buf),stdin);
                append_list_int(&head, (int)atoi(buf));
                break;
            case 4:
                printf("Provide node number to be deleted: ");
                fgets(buf,sizeof(buf),stdin);
                head = delete_node(head, (int)atoi(buf));
                break;
            case 5: puts(""); display_list(head); puts(""); break;
            case 9: exit = 1u; break;
            default: printf("Wrong option.\n"); break;
        }
    }

    (void)*endptr; /* Get rid of warning. */
    return 0;
}