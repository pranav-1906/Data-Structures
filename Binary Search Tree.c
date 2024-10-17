#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node* right;
    struct node* left;
};

struct node* getnode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct node** root, int data) {
    if (*root == NULL) {
        *root = getnode(data);
    } 
    else if (data <= (*root)->data) {
        insert(&((*root)->left), data);
    } 
    else {
        insert(&((*root)->right), data);
    }
}

void search(struct node* root, int data, bool* found) {
    if (root == NULL) {
        *found = false;
    } 
    else if (root->data == data) {
        *found = true;
    } 
    else if (data < root->data) {
        search(root->left, data, found);
    } 
    else {
        search(root->right, data, found);
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    
    printf("Insertion:\n");
    insert(&root, 19);
    insert(&root, 33);
    insert(&root, 14);
    
    printf("In-order traversal:\n");
    inorder(root);
    
    int n;
    bool found = false;
    printf("\nEnter number to search: ");
    scanf("%d", &n);
    
    search(root, n, &found);
    
    if (found) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }
    
    return 0;
}
