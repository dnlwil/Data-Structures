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
        printf("1 - Init List\n2 - Append list\n3 - Delete element\n4 - Display list\n9 - Exit\n");
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
                printf("Provide value to append with: ");
                fgets(buf,sizeof(buf),stdin);
                append_list_int(&head, (int)atoi(buf));
                break;
            case 3: break;
            case 4: display_list(head); break;
            case 9: exit = 1u; break;
            default: printf("Wrong option.\n"); break;
        }

        printf("buf = %s\n", buf);
        printf("choice = %d\n", choice);
    }

    (void)*endptr; /* Get rid of warning. */
    return 0;
}