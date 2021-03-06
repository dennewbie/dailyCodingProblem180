//
//  header.c
//  dailyCodingProblem180
//
//  Created by Denny Caruso on 29/08/2020.
//  Copyright © 2020 Denny Caruso. All rights reserved.
//

#include "header.h"

Node *createNode(void) {
    Node *newNode = (Node *) calloc(1, sizeof(Node));
    if(!newNode) getErrorNodeCreation();
    newNode->nodeData = createData();
    newNode->next = NULL;
    
    return newNode;
}

void getErrorNodeCreation(void) {
    printf("\nError allocating memory for new node... Exit... \n");
    exit(EXIT_FAILURE);
}

Data *createData(void) {
    Data *newData = (Data *) calloc(1, sizeof(Data));
    if(!newData) getErrorDataCreation();
    genData(newData);
    
    return newData;
}

void genData(Data *newData) {
    newData->ID = 1 + rand() % MAX_ID;
}

void getErrorDataCreation(void) {
    printf("\nError allocating memory for new data... Exit... \n");
    exit(EXIT_FAILURE);
}

void printNode(Node *nodeToPrint)  {
    if(nodeToPrint) printf("-> %5d\n", nodeToPrint->nodeData->ID);
}

void printQueue(Node *front) {
    while (!isEmpty(front)) printNode(dequeue(&front));
}

void printStack(Node *head) {
    newLine();
    printf("* Stack Content: *\n\n");
    while (!isEmpty(head)) printNode(pop(&head));
    newLine();
}

unsigned short int generateIntegerNumber() {
    return 1 + rand() % MAX_SIZE;
}

void enqueue(Node **front, Node **rear, Node *newNode) {
    if(!newNode) return;
    
    if(isEmpty(*front)) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

Node *dequeue(Node **front) {
    if(isEmpty(*front)) {
        getMessageIsEmpty(QUEUE);
        return NULL;
    } else {
        Node *dequeuedNode = *front;
        *front = (*front)->next;
        
        return dequeuedNode;
    }
}

void push(Node **head, Node *newNode) {
    if(!newNode) return;
    
    if(isEmpty(*head)) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

Node *pop(Node **head) {
    if(isEmpty(*head)) {
        getMessageIsEmpty(STACK);
        return NULL;
    } else {
        Node *poppedNode = *head;
        *head = (*head)->next;
        
        return poppedNode;
    }
}

Bool isEmpty(Node *front) {
    return !front ? TRUE : FALSE;
}

void getMessageIsEmpty(char *dataStructureString) {
    newLine();
    printf("%s is empty...\n", dataStructureString);
}

void updateStack(Node **head, unsigned short int nNodes) {
    Node *front, *rear;
    front = rear = NULL;
    
    for(int i = 1; i < nNodes - 1; i++) {
        for(int j = 0; j < nNodes - i; j++) {
            Node *poppedNode = pop(head);
            Node *newNode = createNode();
            newNode->nodeData = poppedNode->nodeData;
            enqueue(&front, &rear, newNode);
        }
        
        for(int j = 0; j < nNodes - i; j++) {
            Node *dequeuedNode = dequeue(&front);
            push(head, dequeuedNode);
        }
    }
    
    newLine();
    printf("Updating Stack ...");
}

//    Basic Test for Queue
void testQueue(void) {
    Node *front = NULL, *rear = NULL;
    for(int i = 0; i < 5; i++) {
        Node *newNode = createNode();
        enqueue(&front, &rear, newNode);
    }
    
    printQueue(front); //by value
    
    for(int i = 0; i < 5; i++) {
        Node *dequeuedNode = dequeue(&front);
        printNode(dequeuedNode);
    }
}

//    Basic Test for Stack
void testStack(void) {
    Node *head = NULL;
    for(int i = 0; i < 5; i++) {
        Node *newNode = createNode();
        push(&head, newNode);
    }
    
    printStack(head); //by value
    
    for(int i = 0; i < 5; i++) {
        Node *poppedNode = pop(&head);
        printNode(poppedNode);
    }
}
