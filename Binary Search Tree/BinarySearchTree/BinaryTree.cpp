#include "BinaryTree.h"
#include <iostream>

/**
 * Constructs a BinarySearchTree.
 */
template <typename T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
} //BinaryTree

/**
 * Destructs this BinarySearchTree.
 */
template <typename T>
BinaryTree<T>::~BinaryTree() {
    destroy(root); //Because destructors cannot have parameters, we use destroy to destroy the tree properly
} //~BinaryTree

/**
 * Recursively destroys all nodes in this BinaryTree.
 *
 * @param node the current node to be deleted.
 */
template <typename T>
void BinaryTree<T>::destroy(NodeType<T> *&node) {
    if (node != NULL) {
        destroy(node->left); //We must access children before destroying this node
        destroy(node->right);
        delete node;
    }
} //destroy

/**
 * Inserts a new element into this BinaryTree.
 *
 * @param node the node that is currently being checked.
 * @param key the item to be inserted.
 */
template <typename T>
void BinaryTree<T>::insert(NodeType<T> *&node, T &key) {
    if (node == NULL) { //NULL means we've found the correct spot to insert
        node = new NodeType<T>;
        node->right = NULL;
        node->left = NULL;
        node->key = key;
        if (root == NULL) root = node;
    } else if (key < node->key) { //We must further traverse the left branch
        insert(node->left, key);
    } else if (key > node->key) { //We must further traverse the right branch
        insert(node->right, key);
    } else { //If none of above conditions met, the item is simply already in the tree
        cout << "Item already in tree." << endl;
        return;
    }
} //insert

/**
 * Deletes a specified item from this BinaryTree.
 *
 * @param node the node that is currently being checked,
 * @param key the item to be deleted.
 */
template <typename T>
void BinaryTree<T>::deleteItem(NodeType<T> *&node, T &key) {
    if (node == NULL) { //If we reach a NULL node, that means the item could not be located
        cout << "Item not in tree." << endl;
        return;
    } else if (key < node->key) { //We must further traverse the left branch
        deleteItem(node->left, key);
    } else if (key > node->key) { //We must further traverse the right branch
        deleteItem(node->right, key);
    } else { //We've found the node
        NodeType<T> *temp = node;
        if (node->left == NULL) { //No left child (implicitly includes no left OR right child)
            node = node->right;
            delete temp;
        } else if (node->right == NULL) { //No right child
            node = node->left;
            delete temp;
        } else { //If this node has two children
            getPredecessor(node->left, key); //We must find the logical predecessor
            node->key = key; //And replace this node with it
            deleteItem(node->left, key); //Then delete said node
        }
    }
} //deleteItem

/**
 * Modifies node and key to the logical predecessor of this BinaryTree.
 * A logical predecessor is the largest node on the right side of the binary tree.
 *
 * @param node the parent node where we begin examining.
 * @param key the key to be modified to become the logical predecessor.
 */
template <typename T>
void BinaryTree<T>::getPredecessor(NodeType<T> *node, T &key) {
    while (node->right != NULL) {
        node = node->right;
    } //while
    key = node->key;
} //getPredecessor

/**
 * Determines where or not an item is in this BinaryTree.
 *
 * @param node the node that is currently being examined.
 * @param item the item to be checked if it is in the tree.
 * @param found true if the item is in the tree, false otherwise.
 */
template <typename T>
void BinaryTree<T>::retrieve(NodeType<T> *node, T &item, bool &found) const {
    if (node == NULL) { //NULL node means we couldn't find item
        found = false;
    } else if (item < node->key) { //We must further traverse the left branch
        retrieve(node->left, item, found);
    } else if (item > node->key) { //We must further traverse the right branch
        retrieve(node->right, item, found);
    } else { //None of above conditions met means we found the item
        item = node->key;
        found = true;
    }
} //retrieve

/**
 * Prints out the binary tree using preOrder format.
 * Pre-order means we print this node's key first, then the left then the right child.
 *
 * @param node the node being printed.
 */
template <typename T>
void BinaryTree<T>::preOrder(NodeType<T> *node) const {
    cout.setf(ios::fixed);
    cout.precision(1); //This is to properly format the printing of floats
    if (node != NULL) {
        cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
} //preOrder

/**
 * Prints out this binary tree using In-Order format.
 * In-order means we print out the left child first, then this node and then the right child.
 *
 * @param node the node being printed.
 */
template <typename T>
void BinaryTree<T>::inOrder(NodeType<T> *node) const {
    cout.setf(ios::fixed);
    cout.precision(1);
    if (node != NULL) {
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }
} //inOrder

/**
 * Prints out this binary tree using post-order format.
 * Post-order means we pring out the left and right child first, then this node.
 *
 * @param node the node being printed.
 */
template <typename T>
void BinaryTree<T>::postOrder(NodeType<T> *node) const {
    cout.setf(ios::fixed);
    cout.precision(1);
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->key << " ";
    }
} //postOrder

/**
 * Returns how many nodes are in this binary tree.
 *
 * @param node the node being examined.
 * @returns how many nodes in this specific tree.
 */
template <typename T>
int BinaryTree<T>::getLength(NodeType<T> *node) const {
    if (node == NULL) { //No node here so we do not add
        return 0;
    } else {
        return getLength(node->left) + getLength(node->right) + 1;
    }
} //getLength

/**
 * Returns the root of this BinaryTree by-reference.
 *
 * @returns the root variable.
 */
template <typename T>
NodeType<T>*& BinaryTree<T>::getRoot() {
    return root;
} //getRoot

/**
 * Returns how many nodes in this tree have one child only.
 *
 * @param node the node being examined.
 * @returns how many nodes in this tree have exactly one child.
 */
template <typename T>
int BinaryTree<T>::getNumSingleParent(NodeType<T> *node) const {
    if (node != NULL) { //This will invoke if the previous checked node was a leaf node as well
        if (node->left != NULL && node->right == NULL) { //If we have ONLY a left child
            return getNumSingleParent(node->left) + 1; //We add one, then continue traversing that child
        } else if (node->left == NULL && node->right != NULL) { //If we ONLY have a right child
            return getNumSingleParent(node->right) + 1; //We add one, then continue traversing that child
        } else { //If BOTH or NO children exist
            return getNumSingleParent(node->left) + getNumSingleParent(node->right); //We traverse both children, but do NOT add one
        }
    }
    return 0;
} //getNumSingleParent

/**
 * Returns how many nodes in this tree are leaf nodes (no children).
 *
 * @param node the node being examined.
 * @returns how many nodes in this tree have exactly zero children.
 */
template <typename T>
int BinaryTree<T>::getNumLeafNodes(NodeType<T> *node) const {
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) { //Simply, if there are no children we return one and stop traversing
            return 1;
        } else {
            return getNumLeafNodes(node->left) + getNumLeafNodes(node->right); //Otherwise we continue traversing
        }
    }
    return 0;
} //getNumLeafNodes

/**
 * Returns the sum of the subtrees starting from item.
 *
 * @param node the node being examined.
 * @param item the key where we want to start adding.
 * @param found whether or not we've located the tree where we want to begin summing.
 * @returns the sum of all children below the node of key item.
 */
template <typename T>
T BinaryTree<T>::getSumOfSubtrees(NodeType<T> *node, T &item, bool &found) const {
    if (!found) { //This means we HAVE NOT found the node in the tree yet
        if (node == NULL) {
            found = false;
        } else if (item < node->key) { //So we traverse the branches as normal without adding anything, like in retrieve
            return getSumOfSubtrees(node->left, item, found);
        } else if (item > node->key) {
            return getSumOfSubtrees(node->right, item, found);
        } else { //If we HAVE FOUND the item
            found = true;
            return getSumOfSubtrees(node->left, item, found) + getSumOfSubtrees(node->right, item, found); //This ensures we don't add one extra node
        }
    } else { //This means we HAVE found the node in the tree
        if (node != NULL) { //Therefore we look at all nodes which exist
            return getSumOfSubtrees(node->left, item, found) + getSumOfSubtrees(node->right, item, found) + node->key; //And add their keys
        }
    }
    return 0;
} //getSumofSubtrees

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<string>;
