#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the binary search tree
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to find the value in the BST that is closest to the target
int closestValue(struct TreeNode* root, double target) {
    int closest = root->val;
    struct TreeNode* curr = root;
    while (curr != NULL) {
        if (fabs(target - curr->val) < fabs(target - closest)) {
            closest = curr->val;
        }
        if (target < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return closest;
}

// Function to free the memory allocated for the binary search tree
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Function to print the binary search tree (inorder traversal)
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int n, i;
    double target;

    printf("Enter the number of elements in the binary search tree: ");
    scanf("%d", &n);

    printf("Enter the elements of the binary search tree: ");
    for (i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter the target value: ");
    scanf("%lf", &target);


    int closest = closestValue(root, target);
    printf("Closest number = %d\n", closest);

    // Free the memory allocated for the binary search tree
    freeTree(root);

    return 0;
}