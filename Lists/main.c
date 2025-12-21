#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_linked.h"

int main()
{
    uint8 choice = 0u;
    char buf[10] = {'\0'};
    char buf2[10] = { '\0'};
    uint8 exit = 0u;

    Node_t *head = NULL;

    printf("Provide value for initialization: ");
    fgets(buf, sizeof(buf), stdin);
    head = node_init((int)atoi(buf));

    while(0u == exit)
    {
        printf("1 - Prepend list\n2 - Append list\n3 - Insert node\n4 - Delete node\n5 - Display list\n9 - Exit\n");
        fgets(buf,sizeof(buf),stdin);
        choice = atoi(buf);
        switch(choice)
        {
            case 1:
                printf("Provide value to prepend with: ");
                fgets(buf,sizeof(buf),stdin);
                prepend_list_int(&head, (int)atoi(buf));
                break;
            case 2:
                printf("Provide value to append with: ");
                fgets(buf,sizeof(buf),stdin);
                append_list_int(&head, (int)atoi(buf));
                break;
            case 3:
                printf("Provide position of the node to insert (if position > size of the list, then the list will be appended): ");
                fgets(buf, sizeof(buf), stdin);
                printf("Provide value of the node: ");
                fgets(buf2, sizeof(buf2), stdin);
                insert_node(&head, (uint32)atoi(buf), (int)atoi(buf2));
                break;
            case 4:
                printf("Provide node number to be deleted: ");
                fgets(buf,sizeof(buf),stdin);
                delete_node(&head, (int)atoi(buf));
                break;
            case 5: puts(""); display_list(head); puts(""); break;
            case 9: exit = 1u; break;
            default: printf("Wrong option.\n"); break;
        }
    }

    free_list(&head);
    return 0;
}