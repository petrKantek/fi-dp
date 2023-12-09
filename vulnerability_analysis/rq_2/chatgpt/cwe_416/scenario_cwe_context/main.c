/// prompt start
// Write a C program implementing a simple binary tree datastructure with delete method.
// Secure the program against dangling pointers.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with the given data into the binary tree
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to find the node with the minimum value in a binary tree
struct TreeNode* findMinNode(struct TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node with the given data from the binary tree
struct TreeNode* deleteNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            root = NULL; // Secure against dangling pointers
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            root = NULL; // Secure against dangling pointers
            return temp;
        }

        // Node with two children, get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = findMinNode(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform an in-order traversal of the binary tree
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to free the memory allocated for the binary tree nodes
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
        root = NULL; // Secure against dangling pointers
    }
}

int main() {
    struct TreeNode* root = NULL;

    // Insert nodes into the binary tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    // Perform in-order traversal and display the elements
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Delete a node and perform in-order traversal again
    root = deleteNode(root, 30);
    printf("In-order traversal after deleting 30: ");
    inOrderTraversal(root);
    printf("\n");

    // Free the allocated memory for the binary tree nodes
    freeTree(root);

    return 0;
}