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

struct Node* deleteBeginning(struct Node *head) {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    return head;
}

struct Node* deleteEnd(struct Node *head) {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);

    return head;
}

struct Node* deletePosition(struct Node *head, int position) {
    struct Node *temp;
    int i;

    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    if (position <= 0) {
        printf("Invalid position!\n");
        return head;
    }

    if (position == 1)
        return deleteBeginning(head);

    temp = head;

    for (i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);

    return head;
}

int main() {
    struct Node *head;
    int choice, position;

    head = createList();

    printf("Initial List:\n");
    display(head);

    printf("\n--- DOUBLY LINKED LIST DELETION ---\n");
    printf("1. Delete at Beginning\n");
    printf("2. Delete at Specific Position\n");
    printf("3. Delete at End\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

        case 1:
            head = deleteBeginning(head);
            break;

        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &position);

            head = deletePosition(head, position);
            break;

        case 3:
            head = deleteEnd(head);
            break;

        default:
            printf("Invalid choice!\n");
    }

    printf("\nAfter Deletion:\n");
    display(head);

    return 0;
}