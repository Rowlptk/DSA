#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node *node, int data);
struct Node* new_node(int data);
int height(struct Node *node);
int max(int h1, int h2);
int get_balance(struct Node *node);
struct Node* right_rotate(struct Node *node);
struct Node* left_rotate(struct Node *node);
void traverse_preorder(struct Node *node);
void traverse_inorder(struct Node *node);
void traverse_postorder(struct Node *node);

int main()
{
    struct Node *node = NULL;
    int n, data;
    
    printf("AVL TREE IMPLEMENTATION : ");
    printf("\n--------------------------\n\n");
    
    printf("Enter number of elements : ");
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++)
    {
        printf("Enter data %d : ", i);
        scanf("%d", &data);
        node = insert(node, data);
    }
    
    printf("\n\nPreorder Traverse : \n");
    traverse_preorder(node);
    printf("\n\nInorder Traverse : \n");
    traverse_inorder(node);
    printf("\n\nPostorder Traverse : \n");
    traverse_postorder(node);
    printf("\n");
    return 0;
}

struct Node* insert(struct Node *node, int data)
{
    if(node == NULL)
    {
        return new_node(data);
    }
    
    if(data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = insert(node->right, data);
    }
    else
    {
        return node;
    }
    
    node->height = 1 + max(height(node->left), height(node->right));
    
    int balance = get_balance(node);
    
    if(balance > 1 && data < node->left->data)
    {
        return right_rotate(node);
    }
    
    if(balance < -1 && data > node->right->data)
    {
        return left_rotate(node);
    }
    
    if(balance > 1 && data > node->left->data)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    
    if(balance < -1 && data < node->right->data)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    
    return node;
}

struct Node* left_rotate(struct Node *node)
{
    struct Node *temp, *temp2;
    temp = node->right;
    temp2 = temp->left;
    
    temp->left = node;
    node->right = temp2;
    
    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    
    return temp;
}

struct Node* right_rotate(struct Node *node)
{
    struct Node *temp, *temp2;
    temp = node->left;
    temp2 = temp->right;
    
    temp->right = node;
    node->left = temp2;
    
    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    
    return temp;
}

int get_balance(struct Node *node)
{
    if(node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

int max(int h1, int h2)
{
    return (h1 > h2) ? h1 : h2;
}

int height(struct Node *node)
{
    if(node == NULL)
    {
        return 0;
    }
    return node->height;
}

struct Node* new_node(int data)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

void traverse_preorder(struct Node *node)
{
    if(node != NULL)
    {
        printf("%d ", node->data);
        traverse_preorder(node->left);
        traverse_preorder(node->right);
    }
}

void traverse_inorder(struct Node *node)
{
    if(node != NULL)
    {
        traverse_inorder(node->left);
        printf("%d ", node->data);
        traverse_inorder(node->right);
    }
}

void traverse_postorder(struct Node *node)
{
    if(node != NULL)
    {
        traverse_postorder(node->left);
        traverse_postorder(node->right);
        printf("%d ", node->data);
    }
}