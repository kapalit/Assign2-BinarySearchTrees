#pragma once
// Header file for the BST functions
#ifndef BST_H
#define BST_H

// Define the structure for tree nodes
typedef struct node {
    char data;            
    struct node* left;    
    struct node* right;  
} Node;

// Function prototypes for operations on the bst
Node* insert(Node* root, char data);
Node* newNode(char data);           
void inorderTraversal(Node* root);  
int countNodes(Node* root);          
int treeHeight(Node* root);          
void freeTree(Node* root);          

#endif
