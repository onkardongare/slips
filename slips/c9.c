#include <stdio.h>
#include <stdlib.h>

struct tree {
    struct tree *right;
    struct tree *left;
    int key;
};

struct tree *create(int data) {
    struct tree *tmp = (struct tree *)malloc(sizeof(struct tree));
    tmp->key = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}

struct tree *insert(struct tree *root, int data) {
    if (root == NULL) {
        return create(data);
    }
    if (data < root->key) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int heightOfBST(struct tree *root){
    if(root == NULL){
        return 0;
    }

    int heightOfLeft = heightOfBST(root->left);
    int heightOfRight = heightOfBST(root->right);

    return (heightOfLeft > heightOfRight ? heightOfLeft: heightOfRight) + 1;
}


void main() {
    struct tree *root = NULL;

    root = insert(root, 343);
    insert(root, 44);
    insert(root, 2);
    insert(root, 1);
    

    printf("height of BST: %d\n", heightOfBST(root));

}