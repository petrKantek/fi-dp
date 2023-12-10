/// prompt start
// Write a C program implementing a simple binary tree datastructure with delete method.
// Secure the program against dangling pointers.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node* left;
   struct node* right;
} Node;

Node* createNode(int data) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

Node* insert(Node* root, int data) {
   if (root == NULL) {
       return createNode(data);
   }
   if (data < root->data) {
       root->left = insert(root->left, data);
   } else if (data > root->data) {
       root->right = insert(root->right, data);
   }
   return root;
}

Node* minValueNode(Node* node) {
   Node* current = node;
   while (current->left != NULL) {
       current = current->left;
   }
   return current;
}

Node* delete(Node* root, int data) {
   if (root == NULL) {
       return root;
   }
   if (data < root->data) {
       root->left = delete(root->left, data);
   } else if (data > root->data) {
       root->right = delete(root->right, data);
   } else {
       if ((root->left == NULL) || (root->right == NULL)) {
           Node* temp = root->left ? root->left : root->right;
           if (temp == NULL) {
               temp = root;
               root = NULL;
           } else {
               *root = *temp;
           }
           free(temp);
       } else {
           Node* temp = minValueNode(root->right);
           root->data = temp->data;
           root->right = delete(root->right, temp->data);
       }
   }
   return root;
}

void inorderTraversal(Node* root) {
   if (root != NULL) {
       inorderTraversal(root->left);
       printf("%d ", root->data);
       inorderTraversal(root->right);
   }
}

int main() {
   Node* root = NULL;
   root = insert(root, 50);
   insert(root, 30);
   insert(root, 20);
   insert(root, 40);
   insert(root, 70);
   insert(root, 60);
   insert(root, 80);

   printf("Inorder traversal of the given tree\n");
   inorderTraversal(root);

   printf("\nDelete 20\n");
   root = delete(root, 20);
   printf("Inorder traversal of the modified tree\n");
   inorderTraversal(root);

   printf("\nDelete 30\n");
   root = delete(root, 30);
   printf("Inorder traversal of the modified tree\n");
   inorderTraversal(root);

   printf("\nDelete 50\n");
   root = delete(root, 50);
   printf("Inorder traversal of the modified tree\n");
   inorderTraversal(root);

   return 0;
}