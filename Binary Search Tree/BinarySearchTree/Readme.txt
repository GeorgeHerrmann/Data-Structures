Name: George Herrmann
UGA ID: 811-269-387
UGA Email: gvh12771@uga.edu

To compile:
    - Type make into standard input
To run:
    - Type ./main [FILENAME] where [FILENAME] is replaced with the desired input file
    - Then follow the prompts on screen as appropriate
To clean:
    - Type make clean into standard input

Function Explanations:

GetNumSingleParent:

    if (node != NULL) {
        if (node->left != NULL && node->right == NULL) {
            return getNumSingleParent(node->left) + 1;
        } else if (node->left == NULL && node->right != NULL) {
            return getNumSingleParent(node->right) + 1;
        } else {
            return getNumSingleParent(node->left) + getNumSingleParent(node->right);
        }
    }
    return 0;

This function simply goes through each node as needed and determines where it only has one child. Worst case we must search
both the left and right branch further, decreasing the problem size by one on each branch. Therefore
our reccurence relation is 2 + 2T(n-1), where a = 2, b = 1, c = 2 and k = 1. We invoke the third case of master theorem for
subtract and conquer recurrences and we get O(n).

GetNumLeafNodes:

    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) {
            return 1;
        } else {
            return getNumLeafNodes(node->left) + getNumLeafNodes(node->right);
        }
    }
    return 0;

This function goes through each node and determines if it has zero children. We search all nodes
and decrease our problem size by one each iteration. Therefore our reccurence relation is 1 + T(n-1),
allowing us to invoke the second case of the Master Theorem and we get O(n ^ (0+1)) or simply O(n).

GetSumOfSubtrees

   if (!found) { //This means we HAVE NOT found the node in the tree yet
        if (node == NULL) {
            found = false;
        } else if (item < node->key) {
            return getSumOfSubtrees(node->left, item, found);
        } else if (item > node->key) {
            return getSumOfSubtrees(node->right, item, found);
        } else {
            found = true;
            return getSumOfSubtrees(node->left, item, found) + getSumOfSubtrees(node->right, item, found);
        }
    } else {
        if (node != NULL) {
            return getSumOfSubtrees(node->left, item, found) + getSumOfSubtrees(node->right, item, found) + node->key;
        }
    }
    return 0;

Though the function does search log(n) branches until it finds the correct branch, we are using big O we assume worst case.
Therefore we must assume we must add all N nodes, making our reccurence relation 1 + T(n-1) as our problem size decreases
by for each node we add. We again can use the second case of the Master Theorem and get O(n ^ (0+1)) or simply O(n).
