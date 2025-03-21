#include<stdio.h>
#include<stdlib.h>

struct tree{
    int key;
    struct tree *right, *left;
};

struct tree *create(int data){
    struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
    temp->key = data;
    temp->right = temp->left = NULL;
    return temp;
}

struct tree *insert(struct tree *root, int data){
    if(root == NULL){
        return create(data);
    }
    if(data < root->key){
        root -> left = insert(root->left, data);
    }
    else{
        root -> right = insert(root->right, data);
    }
    return root;
}

int searchKey(struct tree *root, int key){
    if(root == NULL){
        return 0;
    }
    if(root -> key == key){
        return 1;
    }
    if(key < root->key){
        return searchKey(root -> left, key);
    }
    else{
        return searchKey(root -> right, key);
    }
}

void main(){
    struct tree *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 40);
    insert(root, 60);

    int key = 550;
    if(searchKey(root, key)){
        printf("Key %d found in the tree \n", key);
    }
    else{
        printf("Key %d not found in the tree \n", key);
    }
}