//
//  BinaryTreeSearhHeader.hpp
//  BinaryTreeSearch
//
//  Created by Wataru Oshima on 2020/05/03.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#ifndef BinaryTreeSearhHeader_hpp
#define BinaryTreeSearhHeader_hpp

#include <stdio.h>

template <class BSTT>
class BinaryTreeSearchHeader{
private:
    struct node{
        int key;
        node* left;
        node* right;
    };
    
    node* root;
    void addLeafPrivate(int key,  node* Ptr);
    void printlnInOrderPrivate(node* Ptr);
    node* returnNodePrivate(int key, node* Ptr);
    int findSmallestPrivate(node* Ptr);
    void removeNodePrivate(int key, node* parent);
    node* createLeaf(int key);
    node* returnNode(int key);
    void removeSubtree(node* Ptr);
    
public:
    BinaryTreeSearchHeader();
    ~BinaryTreeSearchHeader();
    void addLeaf(int key);
    void printlnInOrder();
    
    int returnRootKey();
    void printChildren(int key);
    int findSmallest();
    void removeNode(int key);
    void removeRootMatch();
    void removeMatch(node* parent, node* match, bool left);
    
    
    void randomNumberGenerator(BSTT list[], int length);
};


#endif /* BinaryTreeSearhHeader_hpp */
