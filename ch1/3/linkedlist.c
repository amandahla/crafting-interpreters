#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *val;
    struct node *next;
} my_node;

int main() {
    my_node *head = NULL;
    head = (my_node *) malloc(sizeof(my_node));
    if (head == NULL) {
        return 1;
    }

    char *str;
    str = (char *) malloc(11);
    strcpy(str, "I'm a node");

    head->val = str;
    head->next = NULL;

    printf("Address = %s\n", head->val);
    return 0;
}