#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a node at the tail
struct Node* insertTail(struct Node* head, int data) {
    struct Node* newnode = createNode(data);
    if (head == NULL) {
        return newnode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

// Function to insert a node at the head
struct Node* insertHead(struct Node* head, int data) {
    struct Node* newnode = createNode(data);
    newnode->next = head;
    return newnode;
}

// Function to insert a node at the kth position
struct Node* insertAtK(struct Node* head, int data, int k) {
    if (k <= 1) {
        return insertHead(head, data); // Insert at head if k is 1 or less
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete the head node
struct Node* deleteHead(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the tail node
struct Node* deleteTail(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete the kth node
struct Node* deleteAtK(struct Node* head, int k) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (k == 1) {
        return deleteHead(head);
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; i < k && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, k;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Insert at kth position\n");
        printf("4. Delete head\n");
        printf("5. Delete tail\n");
        printf("6. Delete kth node\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at head: ");
                scanf("%d", &value);
                head = insertHead(head, value);
                break;
            case 2:
                printf("Enter value to insert at tail: ");
                scanf("%d", &value);
                head = insertTail(head, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at (k): ");
                scanf("%d", &k);
                head = insertAtK(head, value, k);
                break;
            case 4:
                head = deleteHead(head);
                break;
            case 5:
                head = deleteTail(head);
                break;
            case 6:
                printf("Enter position of node to delete (k): ");
                scanf("%d", &k);
                head = deleteAtK(head, k);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
