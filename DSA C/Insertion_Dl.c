#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createList() {
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;

    for (int i = 1; i <= 6; i++) {

        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->data = i;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf("\n");
}

struct Node* insertBeginning(struct Node *head, int value) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    return head;
}

struct Node* insertEnd(struct Node *head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct Node* insertPosition(struct Node *head, int value, int position) {
    struct Node *newNode, *temp;
    int i;

    if (position <= 0) {
        printf("Invalid position!\n");
        return head;
    }

    if (position == 1)
        return insertBeginning(head, value);

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

int main() {
    struct Node *head;
    int choice, value, position;

    head = createList();

    printf("Initial List:\n");
    display(head);

    printf("\n--- DOUBLY LINKED LIST INSERTION ---\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at Specific Position\n");
    printf("3. Insert at End\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);

            head = insertBeginning(head, value);
            break;

        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);

            printf("Enter position: ");
            scanf("%d", &position);

            head = insertPosition(head, value, position);
            break;

        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &value);

            head = insertEnd(head, value);
            break;

        default:
            printf("Invalid choice!\n");
    }

    printf("\nAfter Insertion:\n");
    display(head);

    return 0;
}