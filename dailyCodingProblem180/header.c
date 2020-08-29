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
    getData(newData);
    
    return newData;
}

void getData(Data *newData) {
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

unsigned short int generateIntegerNumber() {
    return 1 + rand() % MAX_SIZE;
}

Bool isEmpty(Node *front) {
    return !front ? TRUE : FALSE;
}

void getMessageIsEmpty(char *dataStructureString) {
    newLine();
    printf("%s is empty...\n", dataStructureString);
}

void enqueue(Node **front, Node **rear, Node *newNode) {
    if(!newNode) getErrorNodeCreation();
    
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

//        Don't free the node ?
        return dequeuedNode;
    }
}

void push(Node **head, Node *newNode) {
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
        
//        Don't free the node ?
        return poppedNode;
    }
}

void printStack(Node *head) {
    while (!isEmpty(head)) printNode(pop(&head));
}
