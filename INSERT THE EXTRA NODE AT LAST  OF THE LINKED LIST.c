#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *link;
};

void insertAtEnd(struct node **head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}

void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("data=%d\n", temp->data);
        temp = temp->link;
    }
}

int main() {
    struct node *head = NULL;

    // Insert initial nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Insert extra node at the end
    insertAtEnd(&head, 40);

    // Print the updated linked list
    printList(head);

    return 0;
}
