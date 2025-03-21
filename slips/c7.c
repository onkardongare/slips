#include <stdio.h>
#include <stdlib.h>

struct tree {
    int key;
    struct tree *right;
    struct tree *left;
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

struct tree *treecopy(struct tree *root){
    struct tree *temp;
    if(root != NULL){
        temp = (struct tree*)malloc(sizeof(struct tree));
        temp -> key = root->key;
        temp ->left = treecopy(root -> left);
        temp -> right = treecopy(root -> right);
        return temp;
    }
    else{
        return NULL;
    }
}

void inorder(struct tree *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct tree *root = NULL;

    root = insert(root, 343);
    insert(root, 44);
    insert(root, 2);
    
    printf("Inorder traversal of the original tree:\n");
    inorder(root);
    printf("\n");

    struct tree *root1 = treecopy(root);

    printf("Inorder traversal of the copied tree:\n");
    inorder(root1);
    printf("\n");

    return 0;
}