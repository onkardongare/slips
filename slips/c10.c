#include<stdio.h>

void main(){
    int i, j, n;

    printf("Enter no. of vertices you want to enter :- \n");
    scanf("%d", &n);

    int m[15][15];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            m[i][j] = 0;
            if(i != j){
                printf("do you want to create an edge between V{%d}-->V{%d} | (1/0) : \n", i+1, j+1);
                scanf("%d",&m[i][j]);
            }
        }
    }

    printf("Your graph is - \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}