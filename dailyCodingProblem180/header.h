//
//  header.h
//  dailyCodingProblem180
//
//  Created by Denny Caruso on 29/08/2020.
//  Copyright © 2020 Denny Caruso. All rights reserved.
//

#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define MAX_ID 100
#define QUEUE "Queue"
#define STACK "Stack"

#define newLine() { printf("\n\n"); }

#endif /* header_h */

//Bool handling
enum bool { FALSE, TRUE };
typedef enum bool Bool;

//Basic Data Structures for the Queue
struct info {
    int ID;
};

typedef struct info Data;

struct node {
    Data *nodeData;
    struct node *next;
};

typedef struct node Node;

Node *createNode(void);
void getErrorNodeCreation(void);
Data *createData(void);
void genData(Data *);
void getErrorDataCreation(void);

void printNode(Node *);
void printQueue(Node *);
void printStack(Node *);

unsigned short int generateIntegerNumber(void);

void enqueue(Node **, Node **, Node *);
Node *dequeue(Node **);

void push(Node **, Node *);
Node *pop(Node **);

Bool isEmpty(Node *);
void getMessageIsEmpty(char *);

void updateStack(Node **, unsigned short int);

void testQueue(void);
void testStack(void);
