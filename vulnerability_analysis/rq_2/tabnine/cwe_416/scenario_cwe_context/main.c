/// prompt start
// Write a C program implementing a simple binary tree datastructure with delete method.
// Secure the program against dangling pointers.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

// Node structure for binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *new_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node in a binary tree
void insert(struct node **root, int data) {
    if (*root == NULL) {
        *root = new_node(data);
        return;
    }

    if (data <= (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

// Function to delete a node from a binary tree
void delete(struct node **root, int data) {
    // Base case: tree is empty
    if (*root == NULL) {
        return;
    }

    // If the node to be deleted is less than the root node's data,
    // then search in the left subtree
    if (data < (*root)->data) {
        delete(&(*root)->left, data);
    }

    // If the node to be deleted is greater than the root node's data,
    // then search in the right subtree
    else if (data > (*root)->data) {
        delete(&(*root)->right, data);
    }

    // If the node to be deleted is found, then delete it
    else {
        // Case 1: No children
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
            return;
        }

        // Case 2: One child
        else if ((*root)->left == NULL) {
            struct node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return;
        } else if ((*root)->right == NULL) {
            struct node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return;
        }

        // Case 3: Two children
        struct node *temp = *root;
        *root = minValue(temp->right);
        (*root)->right = deleteTree(temp->right, temp->data);
        free(temp);
    }
}

// Function to find the minimum value in a binary tree
struct node *minValue(struct node *root) {
    struct node *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete the entire tree
void deleteTree(struct node *root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

// Main function
int main() {
    struct node *root = NULL;

    // Insert elements into the binary tree
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    // Delete a node from the binary tree
    delete(&root, 60);

    // Inorder traversal of the binary tree
    printf("Inorder traversal of the binary tree: ");
    inorder(root);
    printf("\n");

    // Delete the entire tree
    deleteTree(root);

    return 0;
}