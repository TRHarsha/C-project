#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node *newNode(int data)
 {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void print(struct node *root_node)
{
     if (root_node != NULL)
     {
     print(root_node->left);
     printf("%d \n",root_node->data);
     print(root_node->right
     }
}

struct node* insert_node(struct node* node, int value)
{
     if(node == NULL)
     return newNode(data);
     
     if(value < node->data)
     {
     node->left= insert_node(node->lef,data);
     printf("INSERT LEFT VALUE: %d NODE->VALUE: %d \n",data,node->value);
     }
     
     else if (data > node->data}
     {
     node->left= insert_node(node->lef,data);
     printf("INSERT RIGHT VALUE: %d NODE->VALUE: %d \n",data,node->data);
     }
     return node;
}     
     
int main()
{
int arr[20],n;

printf("IMPLEMENTATION OF A BINARY TREE \n\n");
struct node *root_node =NULL;
printf("How many elements do you want to insert: ");
scanf("%d",n);

printf("INSERT NODE: ")
scanf("%d",arr[0]);
root_node =insert_node(root_node, arr[0]);
printf("ROOT IS %d \n",root_node->data);

for(int i=1;i<n;i++)
{
        scanf("%d",arr[i]);
        printf("--------------------------------\n");
        scanf(arr[i]);
        printf("INSERT NODE: %d ROOT NODE: %d\n",arr[i],root_node->data);
        insert_node(root_node,arr[i]);
}
}    
