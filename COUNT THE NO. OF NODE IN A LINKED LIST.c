#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int countNodes(struct node *head) {
    int count = 0;
    struct node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->link;
    }
    return count;
}

int main() {
   	struct node *head=NULL;
	struct node *n1=NULL;
	struct node *n2=NULL;
	struct node *n3=NULL;

    head = (struct node *)malloc(sizeof(struct node));
    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));
    n3 =(struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->link = n1;

    n1->data = 20;
    n1->link = n2;

    n2->data = 30;
    n2->link = n3;
    
    n3->data =40;
    n3->link =NULL;

    printf("data=%d, add=%p\n", head->data, head->link);
    printf("data=%d, add=%p\n", n1->data, n1->link);
    printf("data=%d, add=%p\n", n2->data, n2->link);
        printf("data=%d, add=%p\n", n3->data, n3->link);


    printf("\nNumber of nodes in the linked list: %d\n", countNodes(head));

    return 0;
}
