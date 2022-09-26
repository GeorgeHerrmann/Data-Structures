#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <cstddef>
using namespace std;

/**
 * A NodeType is a Node housed in a BinaryTree that holds some data as well as
 * a left and right child node.
 */
template<class T>
struct NodeType {
    T key;
    NodeType<T> *left;
    NodeType<T> *right;
};

/**
 * A BinarySearchTree is a BinaryTree where each node holds the nodes to the left and the right.
 * The left node is always less than the parent node, the right node is greater.
 */
template<class T> //Can support integers, floats and strings
class BinaryTree {
    private:
        NodeType<T> *root;
    public:
        BinaryTree();
        ~BinaryTree();
        void destroy(NodeType<T> *&node);
        void insert(NodeType<T> *&node, T &key);
        void deleteItem(NodeType<T> *&node, T &key);
        void getPredecessor(NodeType<T> *node, T &key);
        void retrieve(NodeType<T> *node, T &item, bool &found) const;
        void preOrder(NodeType<T> *node) const;
        void inOrder(NodeType<T> *node) const;
        void postOrder(NodeType<T> *node) const;
        int getLength(NodeType<T> *node) const;
        NodeType<T>*& getRoot();
        int getNumSingleParent(NodeType<T> *node) const;
        int getNumLeafNodes(NodeType<T> *node) const;
        T getSumOfSubtrees(NodeType<T> *node, T &item, bool &found) const;
};

#endif
