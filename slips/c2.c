#include<stdio.h>
#include<stdlib.h>

struct tree{
    int key;
    struct tree *right, *left;
};

struct tree *create(int data){
    struct tree *temp = (struct tree*) malloc(sizeof(struct tree));
    temp -> key = data;
    temp -> left = temp -> right = NULL;
    return temp;
}

struct tree *insert(struct tree *root, int data){
    if(root == NULL){
        return create(data);
    }
    if(data < root->key){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

void preorder(struct tree *root){
    if(root != NULL){
    printf(" %d ->",root->key);
    preorder(root->left);
    preorder(root->right);
    }
}


int main(){
    struct tree *root= NULL;

    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);

    preorder(root);
}