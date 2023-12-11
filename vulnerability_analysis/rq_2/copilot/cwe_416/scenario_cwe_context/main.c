/// prompt start
// Write a C program implementing a simple binary tree datastructure with delete method.
// Secure the program against dangling pointers.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insertNode(Node* root, int data) {
    if(root == NULL) {
        root = createNode(data);
    } else if(data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

Node* findMinNode(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int data) {
    if(root == NULL) {
        printf("Element not found.\n");
    } else if(data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Element found
        // Case 1: No child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if(root->left == NULL || root->right == NULL) {
            Node* temp;
            if(root->left == NULL) {
                temp = root->right;
            } else {
                temp = root->left;
            }
            free(root);
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = deleteNode(root, 7);

    return 0;
}