#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *val;
    struct node *prev;
    struct node *next;
} my_node;

// new
// insert
// find
// delete

/* Given a reference (pointer to pointer) to the head of a
   list and an int, inserts a new node on the front of the
   list. */
my_node * newlist(char *str)
{
    my_node *head = NULL;
    head = (my_node *) malloc(sizeof(my_node));
    if (head == NULL) {
        return head;
    }

    head->val = str;
    head->next = NULL;
    head->prev = NULL;

    return head;
}

void push(my_node * head,char *str)
{
    my_node *newnode = NULL;
    newnode = (my_node *) malloc(sizeof(my_node));
    if (newnode == NULL) {
        printf("push: error while malloc");
    }
    newnode->val = str;
    newnode->next = NULL;

    my_node *last = head;
    while (last->next != NULL)
        last = last->next;

    newnode->prev = last;
    last->next = newnode;
}

void printall(my_node * head)
{
    printf("Start Listing\n");
    my_node *last = head;
    while (last != NULL) {
        printf("%s\n", last->val);
        last = last->next;
    }
    printf("End Listing\n");
}

int main() {
    char *str;
    str = (char *) malloc(11);
    strcpy(str, "I'm the head");

    my_node *head = newlist(str);
    printf("Head = %s\n", head->val);

    char *str1;
    str1 = (char *) malloc(11);
    strcpy(str1, "I'm the last");
    push(head,str1);

    printall(head);
    return 0;
}