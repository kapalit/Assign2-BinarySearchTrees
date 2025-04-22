#include "BST.h"
#include <stdlib.h>

// Function to create a new tree node with the given data
Node* newNode(char data) {
    Node* temp = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
    temp->data = data;                        // Set node's data
    temp->left = temp->right = NULL;          // Initialize left and right children as NULL
    return temp;
}

// Function to insert a new node with the given data into the tree
Node* insert(Node* root, char data) {
    if (root == NULL) {                      // If the tree is empty, the new node becomes the root
        root = newNode(data);
    }
    else if (data < root->data) {          // If the data is less than the root's data, insert in left subtree
        root->left = insert(root->left, data);
    }
    else {                                 // Otherwise, insert in right subtree
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform in-order traversal of the tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);        // Visit left subtree
        printf("%c ", root->data);           
        inorderTraversal(root->right);       // Visit right subtree
    }
}

// Function to count the number of nodes in the tree
int countNodes(Node* root) {
    if (root == NULL)                        
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right); // Return the total count of nodes
}

// Function to determine the height of the tree
int treeHeight(Node* root) {
    if (root == NULL)                       
        return -1;
    int leftHeight = treeHeight(root->left); // Height of left subtree
    int rightHeight = treeHeight(root->right); // Height of right subtree
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight); // Returns the greater height
}

// Function to free the memory allocated for the tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);                // Frees left subtree
        freeTree(root->right);               // Frees right subtree
        free(root);                          
    }
}
