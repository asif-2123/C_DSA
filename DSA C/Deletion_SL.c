#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList() {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 1; i <= 6; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" -> ");

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

    free(temp);

    return head;
}

struct Node* deleteEnd(struct Node *head) {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    temp = head;
    prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    free(temp);

    return head;
}

struct Node* deletePosition(struct Node *head, int position) {
    struct Node *temp, *deleteNode;
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

    for (i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;

    free(deleteNode);

    return head;
}

int main() {
    struct Node *head;
    int choice, position;

    head = createList();

    printf("Initial List:\n");
    display(head);

    printf("\n--- SINGLY LINKED LIST DELETION ---\n");
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