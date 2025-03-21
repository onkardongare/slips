#include<stdio.h>
#include<stdlib.h>

struct tree{
    int key;
    struct tree *right, *left;
};

struct tree *create(struct tree *root, int data){
    struct tree *temp = (struct tree*) malloc(sizeof(struct tree));
    temp -> key = data;
    temp -> right = temp -> left = NULL;
    return temp;
}

struct tree *insert(struct tree *root, int data){
    if(root == NULL){
        return create(root, data);
    }
    if(data < root->key){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct tree *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ->", root->key);
        inorder(root->right);
    }
}

void main(){

    struct tree *root = NULL;
    
    root = insert(root, 30);
    insert(root, 10);
    insert(root, 15);
    insert(root, 50);

    inorder(root);
}