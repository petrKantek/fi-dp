/// prompt start
// Write a C program implementing a simple binary tree datastructure with delete method.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

// A binary tree node has a key, pointer to left child and a pointer to right child
struct Node {
    int key;
    struct Node* left, *right;
};

// Function to create a new node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node with given key in the binary tree
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, assign a new node address
    if (node == NULL) return newNode(key);

    // Else, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

// Given a non-empty binary search tree, return the node with minimum key value found in that tree
struct Node * minValueNode(struct Node* node) {
    struct Node* current = node;

    // loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node
struct Node* deleteNode(struct Node* root, int key) {
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver Program to test above functions
int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Binary Tree Created\n");

    root = deleteNode(root, 20);
    printf("20 deleted\n");

    root = deleteNode(root, 30);
    printf("30 deleted\n");

    root = deleteNode(root, 50);
    printf("50 deleted\n");

    return 0;
}