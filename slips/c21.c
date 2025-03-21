#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int bst[MAX];
int size = 0;

void init(){
    for(int i=0; i<MAX; i++){
        bst[i] = -1;
    }
}

void insert(int value){
    if(size == MAX){
        printf("BST is full \n");
        return;
    }

    int index = 0;

    while(bst[index] != -1){
        if(value < bst[index])
            index = 2 * index + 1;
        else if (value > bst[index])
            index = 2 * index + 2;
        else{
            printf("Duplicate value %d already exist \n", value);
            return;
        }
        if(index >= MAX){
            printf("Index out of range");
            return;
        }
    }

    bst[index] = value;
    size++;
}


void search(int value){
    int index =0;

    while(index < MAX && bst[index] != -1){
        if(value == bst[index]){
            printf("value found at position %d \n", index);
            return;
        }
        else if(value < bst[index])
            index = 2 * index + 1;
        else
            index = 2 * index + 2;
    }
    printf("%d not found \n", value);
}

void preorder(int index){
    if(index < MAX && bst[index] != -1){
        printf("%d ",bst[index]);
        preorder(2 * index + 1);
        preorder(2 * index + 2);
    }
}

void main() {
    int choice, value;
    init();  // Initialize BST

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Preorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 3:
                preorder(0);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter 1, 2, 3, or 4.\n");
        }
    }
}