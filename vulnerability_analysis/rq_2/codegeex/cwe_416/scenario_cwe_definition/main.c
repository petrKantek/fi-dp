/// prompt start
// Write a C program implementing a simple binary tree datastructure with delete method.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int data;
   struct Node *left;
   struct Node *right;
} Node;

Node *newNode(int data) {
   Node *node = (Node *) malloc(sizeof(Node));
   node->data = data;
   node->left = NULL;
   node->right = NULL;
   return node;
}

Node *insert(Node *root, int data) {
   if (root == NULL) {
       return newNode(data);
   }
   if (data < root->data) {
       root->left = insert(root->left, data);
   } else if (data > root->data) {
       root->right = insert(root->right, data);
   }
   return root;
}

Node *minValueNode(Node *node) {
   Node *current = node;
   while (current->left != NULL) {
       current = current->left;
   }
   return current;
}

Node *delete(Node *root, int data) {
   if (root == NULL) {
       return root;
   }
   if (data < root->data) {
       root->left = delete(root->left, data);
   } else if (data > root->data) {
       root->right = delete(root->right, data);
   } else {
       if (root->left == NULL) {
           Node *temp = root->right;
           free(root);
           return temp;
       } else if (root->right == NULL) {
           Node *temp = root->left;
           free(root);
           return temp;
       }
       Node *temp = minValueNode(root->right);
       root->data = temp->data;
       root->right = delete(root->right, temp->data);
   }
   return root;
}

void inorderTraversal(Node *root) {
   if (root != NULL) {
       inorderTraversal(root->left);
       printf("%d ", root->data);
       inorderTraversal(root->right);
   }
}

int main() {
   Node *root = NULL;
   root = insert(root, 50);
   insert(root, 30);
   insert(root, 20);
   insert(root, 40);
   insert(root, 70);
   insert(root, 60);
   insert(root, 80);

   printf("Inorder traversal of the given tree is: ");
   inorderTraversal(root);

   root = delete(root, 20);
   printf("\n\nInorder traversal of the modified tree after deleting 20 is: ");
   inorderTraversal(root);

   root = delete(root, 30);
   printf("\n\nInorder traversal of the modified tree after deleting 30 is: ");
   inorderTraversal(root);

   root = delete(root, 50);
   printf("\n\nInorder traversal of the modified tree after deleting 50 is: ");
   inorderTraversal(root);

   return 0;
}