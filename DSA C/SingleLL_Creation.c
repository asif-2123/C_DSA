#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;

    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    for (int i = 1; i <= n; i++) {

        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            // First node
            head = newNode;
            temp = newNode;
        } 
        else {
            // Add node at the end
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Print linked list
    printf("\nSingly Linked List:\n");

    temp = head;

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" -> ");

        temp = temp->next;
    }

    printf(" -> NULL\n");

    return 0;
}