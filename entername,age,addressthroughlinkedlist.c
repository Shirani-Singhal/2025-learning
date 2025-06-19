#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the linked list node
struct Node {
    char name[50];
    int age;
    char address[100];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char name[], int age, char address[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    strcpy(newNode->address, address);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(struct Node** head, char name[], int age, char address[]) {
    struct Node* newNode = createNode(name, age, address);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("\nStored information:\n");
    while (temp != NULL) {
        printf("Name: %s\nAge: %d\nAddress: %s\n\n", temp->name, temp->age, temp->address);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, i, age;
    char name[50], address[100];

    // Input the number of entries
    printf("Enter the number of people: ");
    scanf("%d", &n);

    // Accept details and store them in the linked list
    for ( i = 0; i < n; i++) {
        printf("\nEnter details for person %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", name); // This allows spaces in the name
        printf("Age: ");
        scanf("%d", &age);
        printf("Address: ");
        scanf(" %[^\n]", address); // This allows spaces in the address

        insertNode(&head, name, age, address);
    }

    // Display the linked list
    displayList(head);

    return 0;
}
