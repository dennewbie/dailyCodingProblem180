//
//  main.c
//  dailyCodingProblem180
//
//  Created by Denny Caruso on 29/08/2020.
//  Copyright © 2020 Denny Caruso. All rights reserved.
//

/*
    This problem was asked by Google.

    Given a stack of N elements, interleave the first half of the stack with the second half reversed
    using only one other queue. This should be done in-place.

    Recall that you can only push or pop from a stack, and enqueue or dequeue from a queue.
    For example, if the stack is [1, 2, 3, 4, 5], it should become [1, 5, 2, 4, 3].
    If the stack is [1, 2, 3, 4], it should become [1, 4, 2, 3].
 */

#include "header.h"

int main(int argc, const char * argv[]) {
    srand((unsigned int) time(NULL));
    
    Node *head = NULL;
    unsigned short int nNodes = generateIntegerNumber();
    
    for(int i = 0; i < nNodes; i++) {
        Node *newNode = createNode();
        push(&head, newNode);
    }
    
    printStack(head); //by value
    updateStack(&head, nNodes);
    printStack(head); //by value
    return 0;
}
