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
// delete v

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

void delete(my_node * head,char *str)
{
    my_node *result = find(head,str);
    if (result != NULL) {
        printf("Deleting: %s\n",str);
        my_node *newnext = result->next;
        result->prev->next = newnext;
    }else{
        printf("Not found, no action");
    }
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
    strcpy(str, "Node 1");
    my_node *head = newlist(str);
    printf("Head = %s\n", head->val);

    char *str1;
    str1 = (char *) malloc(11);
    strcpy(str1, "Node 2");
    insert(head,str1);

    char *str2;
    str2 = (char *) malloc(11);
    strcpy(str2, "Node 3");
    insert(head,str2);

    printall(head);

    printf("Find: %s\n",str1);
    my_node *result = find(head,str1);
    if (result != NULL) {
        printf("Found: %s\n",result->val);
    }else{
        printf("not found");
    }

    printf("Delete: %s\n",str1);
    delete(head,str1);

    printall(head);
    return 0;
}