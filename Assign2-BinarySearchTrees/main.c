#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // random number generator
    int n = 11 + rand() % 10; // Generates a random number of characters between 11 and 20

    Node* root = NULL; 
    printf("Inserted characters: ");
    for (int i = 0; i < n; i++) {
        char randomChar = 'a' + rand() % 26; // Generates a random lowercase letter
        printf("%c ", randomChar);
        root = insert(root, randomChar); // Inserts the character into the BST
    }
    printf("\n");

    printf("Sorted characters: ");
    inorderTraversal(root); // Prints the characters in sorted order using in-order traversal
    printf("\n");

    printf("Number of nodes: %d\n", countNodes(root)); 
    printf("Tree height: %d\n", treeHeight(root)); 

    freeTree(root); // Free the memory allocated 
    return 0;
}
