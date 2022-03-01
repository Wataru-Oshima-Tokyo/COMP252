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
#include <string>
template <class BSTT>
class BinaryTreeSearchHeader{
private:
    struct node{
        BSTT key;
        node* left;
        node* right;
    };
    
    node* root;
    void addLeafPrivate(BSTT key,  node* Ptr);
    void printlnInOrderPrivate(node* Ptr);
    node* returnNodePrivate(BSTT key, node* Ptr);
    BSTT findSmallestPrivate(node* Ptr);
    void removeNodePrivate(BSTT key, node* parent);
    node* createLeaf(BSTT key);
    node* returnNode(BSTT key);
    void removeSubtree(node* Ptr);
    void preOrderPrivate(node* Ptr);
    void postOrderPrivate(node* Ptr);
    int countHeightPrivate(node* Ptr);
    int countLeavesPrivate(node* Ptr);
    
public:
    BinaryTreeSearchHeader();
    ~BinaryTreeSearchHeader();
    void addLeaf(BSTT key);
    void printlnInOrder();
    void preOrder();
    void postOrder();
    BSTT returnRootKey();
    void printChildren(BSTT key);
    BSTT findSmallest();
    void removeNode(BSTT key);
    void removeRootMatch();
    void removeMatch(node* parent, node* match, bool left);
    int countHeight();
    int countLeaves();
    
    void randomNumberGenerator(BSTT list[], int length);
};


#endif /* BinaryTreeSearhHeader_hpp */
