#include<stdio.h>
#define size 7
int arr[size];
void init()
{   
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}
void insert(int value)
{   
    int key = value % size;
    
    if(arr[key] == -1)
    {   
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }
    else
    {   
        printf("Collision : arr[%d] has element %d already!\n",key,arr[key]);
        printf("Unable to insert %d\n",value);
    }
}

void print()
{
    for(int i = 0; i < size; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}
int main()
{
    init();
    insert(10); //key = 10 % 7 ==> 3
    insert(4);  //key = 4 % 7  ==> 4
    insert(2);  //key = 2 % 7  ==> 2
    insert(3);  //key = 3 % 7  ==> 3 (collision)

    printf("Hash table\n");
    print();
    printf("\n");
    
    return 0;
}
