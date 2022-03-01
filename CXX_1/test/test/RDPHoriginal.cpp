//
//  RDPHeader.cpp
//  comp252Project
//
//  Created by Wataru Oshima on 2020/05/10.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include "RDPHoriginal.hpp"
#include <iostream>

struct node {
    int data;
    struct node *next;
};

node *start=NULL;
node *createNode(){
    node *temp;
    temp = new node;
    return temp;
}


int RDPHoriginal::searchNDP(int deapthInput)
{
    //searching NDP but need to fix it to be more efficient
    if (deapthInput > 42) {
        return 0;
    }
    else {
        for (int i = 0; i<length; i++) {
            if (deapthInput == NDP[i])
            {
                return NDP[i];
            }
        }
    }
    return -1;
}

//void RDPHoriginal::initializeNode()
//{
//    node *temp, *traverse;
//    for (int i = 0; i<length; i++) {
//        temp = createNode();
//        temp->data = deapth[i];
//        temp->next = NULL;
//        if (start == NULL) {
//            start = temp;
//        }
//        else
//        {
//            traverse = start;
//            while(traverse->next != NULL){
//                traverse= traverse->next;
//            }
//            traverse->next= temp;
//            }
//        }
//}

void RDPHoriginal::initializeNode()
{
    
}

void RDPHoriginal::println()
{
    int j = 1;
    node *traverseNode = start;

    while(traverseNode != NULL){
        std::cout<<traverseNode->data<< " ";
        traverseNode = traverseNode->next;
        j = ++j;
        }
}
