#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *val;
    struct node *prev;
    struct node *next;
} my_node;

// new v
// insert v
// find v
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

my_node * find(my_node * head,char *str)
{
    my_node *last = head;
    while (last != NULL) {
        if (strcmp(last->val,str) == 0) {
            return last;
        }
        last = last->next;
    }
    return NULL;
}

void insert(my_node * head,char *str)
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
    insert(head,str1);

    printall(head);

    printf("Find: %s\n",str1);

    my_node *result = find(head,str1);
    if (result != NULL) {
        printf("Found: %s\n",result->val);
    }else{
        printf("not found");
    }

    return 0;
}