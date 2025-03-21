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

int leafNodes(struct tree *root){
    if(root == NULL){
        return 0;
    }
    if(root -> left == NULL && root -> right == NULL){
        return 1;
    }
    return leafNodes(root->right) + leafNodes(root -> left);
}

void main(){
    struct tree *root=NULL;

    root = insert(root, 20);
    insert(root, 399);
    insert(root, 11);
    
    preordr(root);
    printf("Leaf Nodes are %d", leafNodes(root));
}