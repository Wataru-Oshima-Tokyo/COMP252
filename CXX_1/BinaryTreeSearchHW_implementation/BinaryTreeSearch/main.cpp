//
//  main.cpp
//  BinaryTreeSearch
//
//  Created by Wataru Oshima on 2020/05/03.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <random>
#include "BinaryTreeSearhHeader.cpp"
using namespace std;

//template <class BSTT>
//class BinaryTreeSearchHeader{
//private:
//    struct node{
//        BSTT key;
//        node* left;
//        node* right;
//    };
//
//    node* root;
//    void addLeafPrivate(BSTT key,  node* Ptr);
//    void printlnInOrderPrivate(node* Ptr);
//    node* returnNodePrivate(BSTT key, node* Ptr);
//    BSTT findSmallestPrivate(node* Ptr);
//    void removeNodePrivate(BSTT key, node* parent);
//    node* createLeaf(BSTT key);
//    node* returnNode(BSTT key);
//    void removeSubtree(node* Ptr);
//    void preOrderPrivate(node* Ptr);
//    void postOrderPrivate(node* Ptr);
//    int countHeightPrivate(node* Ptr);
//    int countLeavesPrivate(node* Ptr);
//
//public:
//    BinaryTreeSearchHeader();
//    ~BinaryTreeSearchHeader();
//    void addLeaf(BSTT key);
//    void printlnInOrder();
//    void preOrder();
//    void postOrder();
//    BSTT returnRootKey();
//    void printChildren(BSTT key);
//    BSTT findSmallest();
//    void removeNode(BSTT key);
//    void removeRootMatch();
//    void removeMatch(node* parent, node* match, bool left);
//    int countHeight();
//    int countLeaves();
//
//    void randomNumberGenerator(BSTT list[], int length);
//};
//
//
//template <class BSTT>
//BinaryTreeSearchHeader<BSTT>::BinaryTreeSearchHeader()
//{
//    root = NULL;
//}
//template <class BSTT>
//typename BinaryTreeSearchHeader<BSTT>::node*  BinaryTreeSearchHeader<BSTT>::createLeaf(BSTT key)
//{
//    node* n = new node;
//    n->key = key;
//    n->left = NULL;
//    n->right = NULL;
//    return n;
//}
//
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::addLeaf(BSTT key)
//{
//    addLeafPrivate(key, root);
//}
//
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>:: addLeafPrivate(BSTT key, node* Ptr)
//{
//    if (root == NULL) {
//        root = createLeaf(key);
//    }
//    else if (key < Ptr->key) {
//        if (Ptr->left != NULL)
//            addLeafPrivate(key, Ptr->left);
//        else
//            Ptr->left = createLeaf(key);
//    }
//    else if  (key > Ptr->key) {
//           if (Ptr->right != NULL)
//               addLeafPrivate(key, Ptr->right);
//           else
//               Ptr->right = createLeaf(key);
//    } else {
//        cout << "The key " << key << " has already been added to the tree" << endl;
//    }
//
//}
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::printlnInOrder(){
//    printlnInOrderPrivate(root);
//}
//
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::printlnInOrderPrivate(node* Ptr){
//    if (root != NULL) {
//        if (Ptr->left != NULL) {
//            printlnInOrderPrivate(Ptr->left);
//        }
//        cout << Ptr->key << " ";
//        if (Ptr->right != NULL) {
//            printlnInOrderPrivate(Ptr->right);
//        }
//
//    }else {
//        cout << "The tree is empty" << endl;
//    }
//}
//template <class BSTT>
//typename BinaryTreeSearchHeader<BSTT>::node* BinaryTreeSearchHeader<BSTT>::returnNode(BSTT key) {
//    return returnNodePrivate(key, root);
//}
//
//template <class BSTT>
//typename BinaryTreeSearchHeader<BSTT>::node* BinaryTreeSearchHeader<BSTT>::returnNodePrivate(BSTT key, node* Ptr) {
//
//    if (Ptr != NULL) {
//        if(Ptr->key == key) {
//            return Ptr;
//        }
//        else {
//            if (key < Ptr->key)
//                return returnNodePrivate(key, Ptr->left);
//            else
//                return returnNodePrivate(key, Ptr->right);
//        }
//    } else
//        return NULL;
//}
//template <class BSTT>
//BSTT BinaryTreeSearchHeader<BSTT>::returnRootKey(){
//    if (root !=NULL) {
//        return root->key;
//    }
//    else
//        return -1;
//}
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::printChildren(BSTT key){
//    node* Ptr = returnNode(key);
//
//    if (Ptr != NULL) {
//        cout << "Parent node is " << Ptr->key << endl;
//        Ptr->left == NULL ?
//        cout << "Left child = NULL" << endl:
//        cout << "Left child = " << Ptr->left->key << endl;
//
//        Ptr->right == NULL ?
//        cout << "Right child = NULL" << endl:
//        cout << "Right child = " << Ptr->right->key << endl;
//    } else
//        cout << "The key " << key << " does not exist in the tree" << endl;
//}
//
//template <class BSTT>
//BSTT BinaryTreeSearchHeader<BSTT>::findSmallest()
//{
//    return findSmallestPrivate(root);
//}
//
//template <class BSTT>
//BSTT BinaryTreeSearchHeader<BSTT>::findSmallestPrivate(node* Ptr)
//{
//
//    if (root == NULL) {
//        cout << "The tree is empty" << endl;
//        return NULL;
//    } else {
//        if (Ptr->left != NULL) {
//            return findSmallestPrivate(Ptr->left);
//            }
//        else
//            return Ptr->key;
//    }
//
//}
//
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::removeNode(BSTT key)
//{
//    removeNodePrivate(key, root);
//}
//
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::removeNodePrivate(BSTT key, node* parent)
//{
//    if (root != NULL) {
//        if (root->key == key) {
//            removeRootMatch();
//        }
//        else {
//            if (key < parent->key && parent->left != NULL) {
//                parent->left->key == key ?
//                removeMatch(parent, parent->left, true):
//                removeNodePrivate(key, parent->left);
//            }
//            else if (key > parent->key && parent->right != NULL) {
//                parent->right->key == key ?
//                removeMatch(parent, parent->right, false):
//                removeNodePrivate(key, parent->right);
//            }
//            else
//            {
//                cout << "The key " << key << " was not found in the tree\n";
//            }
//        }
//    } else {
//        cout << "The tree is empty\n";
//    }
//}
//
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::removeRootMatch()
//{
//    if (root != NULL) {
//        node* delPtr = root;
//        BSTT rootKey = root->key;
//        BSTT smallestRightSubtree;
//
//        //case 0 - no children
//        if (root->left == NULL && root->right == NULL)
//        {
//            root = NULL;
//            delete delPtr;
//        }
//        //case 1 - 1 child
//        else if (root->left == NULL && root->right != NULL) {
//            root = root->right;
//            delPtr->right = NULL;
//            delete delPtr;
//            cout << "The root node with key " << rootKey << " was deleted. " << "The new root contains key " << root->key << endl;
//        }
//        else if (root->left != NULL && root->right == NULL)
//        {
//        root = root->left;
//            delPtr->left = NULL;
//        delete delPtr;
//        cout << "The root node with key " << rootKey << " was deleted. " << "The new root contains key " << root->key << endl;
//
//        }
//        // case 2 - 2 children
//
//        else
//        {
//            smallestRightSubtree = findSmallestPrivate(root->right);
//            removeNodePrivate(smallestRightSubtree, root);
//            root->key = smallestRightSubtree;
//            cout << "The root node with key " << rootKey << " was overwritten with key " <<  root->key << endl;
//        }
//
//
//    } else {
//        cout << "The tree is empty\n";
//    }
//}
//
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::removeMatch(node* parent, node* match, bool left)
//{
//    if (root != NULL) {
//        node* delPtr;
//        BSTT matchKey = match->key;
//        BSTT smallestRightSubtree;
//
//        //case 0 - no children
//        if (match->left == NULL && match->right == NULL ) {
//            delPtr = match;
//            left == true ? parent->left = NULL : parent->right = NULL;
//            delete delPtr;
//            cout << "The node containing key " << matchKey << " was removed\n";
//        }
//        //case 1 - 1 child
//        else if (match->left == NULL && match->right != NULL )
//        {
//            left == true ? parent->left = match->right : parent->right = match->right;
//            match->right = NULL;
//            delPtr = match;
//            delete delPtr;
//            cout << "The node containing key " << matchKey << " was removed\n";
//        }
//        else if (match->left != NULL && match->right == NULL )
//        {
//            left == true ? parent->left = match->left : parent->right = match->left;
//            match->left = NULL;
//            delPtr = match;
//            delete delPtr;
//            cout << "The node containing key " << matchKey << " was removed\n";
//        }
//        //case 2 - 2 children
//        else
//        {
//            smallestRightSubtree =  findSmallestPrivate(match->right);
//            removeNodePrivate(smallestRightSubtree, match);
//            match->key = smallestRightSubtree;
//        }
//    } else {
//        cout << "The tree is empty\n";
//    }
//}
//
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::removeSubtree(node* Ptr)
//{
//    if (Ptr != NULL) {
//        if (Ptr->left != NULL) {
//            removeSubtree(Ptr->left);
//        }
//        if (Ptr->left != NULL) {
//            removeSubtree(Ptr->right);
//        }
////        cout << "Deleting the node containing key " << Ptr->key << endl;
//        delete Ptr;
//    }
//}
//
//template <class BSTT>
//BinaryTreeSearchHeader<BSTT>::~BinaryTreeSearchHeader()
//{
//    removeSubtree(root);
//}
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::preOrder()
//{
//    preOrderPrivate(root);
//}
//
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::postOrder()
//{
//    postOrderPrivate(root);
//}
//
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::preOrderPrivate(node* Ptr)
//{
//    if (Ptr != NULL) {
//        cout << Ptr->key << " ";
//        preOrderPrivate(Ptr->left);
//        preOrderPrivate(Ptr->right);
//    }
//
//}
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::postOrderPrivate(node* Ptr)
//{
//    if (Ptr != NULL) {
//        postOrderPrivate(Ptr->left);
//        postOrderPrivate(Ptr->right);
//        cout << Ptr->key << " ";
//    }
//}
//
//template <class BSTT>
//int BinaryTreeSearchHeader<BSTT>::countHeight()
//{
//    return countHeightPrivate(root);
//}
//
//template <class BSTT>
//int BinaryTreeSearchHeader<BSTT>::countHeightPrivate(node* Ptr)
//{
//    int a = 0, b = 0;
//
//    if(Ptr == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        a = countHeightPrivate(Ptr->left)+1;
//        b = countHeightPrivate(Ptr->right)+1;
//    }
//
//    if (a >= b)
//        return a;
//    else
//        return b;
//}
//template <class BSTT>
//int BinaryTreeSearchHeader<BSTT>::countLeavesPrivate(node* Ptr)
//{
//    if (root == NULL) {
//        return 0;
//    }
//    if (Ptr == NULL) {
//        return 0;
//    }
//    if (Ptr->right == NULL && Ptr->left == NULL) {
//        return 1;
//    }
//
//    return countLeavesPrivate(Ptr->right) + countLeavesPrivate(Ptr->left);
//
//}
//
//template <class BSTT>
//int BinaryTreeSearchHeader<BSTT>::countLeaves(){
//    return countLeavesPrivate(root);
//}
//
//
//template <class BSTT>
//void BinaryTreeSearchHeader<BSTT>::randomNumberGenerator(BSTT list[], int length)
//{
//    int scope = length * 5;
//    random_device m;
//    mt19937 mt(m());
//    uniform_int_distribution<> rand100(0,scope);
//    for (int i = 0; i<length; i++) {
//        list[i] = rand100(mt);
//    }
//}



int main(int argc, const char * argv[]) {
    BinaryTreeSearchHeader<int> Tree1;
    BinaryTreeSearchHeader<int> Tree2;
    BinaryTreeSearchHeader<int> Tree3;
//    int list[20];
    int length = 20;
//    string list[20] = {"A", "}
//    Tree1.randomNumberGenerator(list, length);
//    Tree2.randomNumberGenerator(list, length);
//    Tree3.randomNumberGenerator(list, length);
//    cout << "The list before adding numbers: " << endl;
    Tree1.printlnInOrder();
    for (int i = 0; i<length; i++) {
        Tree1.addLeaf(list[i]);
    }
    cout << endl;
    cout << "The list of the post order for the tree 1 is: " << endl;
    Tree1.preOrder();
    cout << endl;
    for (int i = 0; i<length; i++) {
        Tree2.addLeaf(list[i]);
    }
    cout << endl;
    cout << "The list of the pre order for the tree 2 is: " << endl;
    Tree2.postOrder();
    cout << endl;
    for (int i = 0; i<length; i++) {
        Tree3.addLeaf(list[i]);
    }
    cout << endl;
    cout << "The list in order for the tree 3 is: " << endl;
    Tree3.printlnInOrder();
    cout << endl;

    cout << "The height for the tree 1 is " << Tree1.countHeight();
    cout << ". And the leaves are " << Tree1.countLeaves() << endl;
    return 0;
}

