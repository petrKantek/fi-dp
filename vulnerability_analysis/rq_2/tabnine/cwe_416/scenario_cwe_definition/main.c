/// prompt start
// Write a C program implementing a simple binary tree datastructure with delete method.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// Function to create a new node
struct node *new_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the binary tree
void insert(int data) {
    struct node *new_node = new_node(data);
    if (root == NULL) {
        root = new_node;
        return;
    }
    struct node *temp = root;
    while (1) {
        if (data <= temp->data) {
            if (temp->left == NULL) {
                temp->left = new_node;
                break;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = new_node;
                break;
            }
            temp = temp->right;
        }
    }
}

// Function to delete a node from the binary tree
void delete(int data) {
    struct node *temp = root;
    struct node *parent = NULL;
    while (temp != NULL) {
        parent = temp;
        if (data < temp->data) {
            temp = temp->left;
        } else if (data > temp->data) {
            temp = temp->right;
        } else {
            // Found the node to be deleted
            break;
        }
    }
    if (temp == NULL) {
        return;
    }
    // Node found, now delete it
    if (temp->left == NULL && temp->right == NULL) {
        if (parent->left == temp) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(temp);
        return;
    }
    // Node has one child
    if (temp->left == NULL) {
        if (parent->left == temp) {
            parent->left = temp->right;
        } else {
            parent->right = temp->right;
        }
        free(temp);
        return;
    }
    if (temp->right == NULL) {
        if (parent->left == temp) {
            parent->left = temp->left;
        } else {
            parent->right = temp->left;
        }
        free(temp);
        return;
    }
    // Node has two children
    struct node *min_node = temp->right;
    while (min_node->left != NULL) {
        parent = min_node;
        min_node = min_node->left;
    }
    temp->data = min_node->data;
    if (parent->left == temp) {
        parent->left = min_node->right;
    } else {
        parent->right = min_node->right;
    }
    free(min_node);
}

// Function to print the inorder traversal of the binary tree
void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(data);
    }
    printf("Inorder traversal of the binary tree is: ");
    inorder(root);
    printf("\n");
    printf("Enter the data of the node to be deleted: ");
    scanf("%d", &data);
    delete(data);
    printf("Inorder traversal of the binary tree after deleting the node is: ");
    inorder(root);
    return 0;
}