#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push_front(struct Node** headRef, int data){
    struct Node* newNode = createNode(data);
    newNode->next= *headRef;
    *headRef= newNode;
}

void push_back(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next =NULL;
    if(*headRef ==NULL){
        *headRef = newNode;
        return;
    }
    struct Node* curr = *headRef;
    while(curr->next !=NULL){
        curr= curr->next;
    }
    curr->next = newNode;

}

void printList(struct Node* head){
    struct Node* curr = head;
    while (curr != NULL){
        printf("%d -> ", curr->data);
        curr = curr-> next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_front(&head, 5);
    printList(head);
    return 0;
}

