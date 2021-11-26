#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* new_node(int data);
struct Node* right_rotate(struct Node *node);
struct Node* left_rotate(struct Node *node);
struct Node* insert(struct Node *node, int data);
struct Node* splay(struct Node *node, int data);
void traverse_preorder(struct Node *node);
void traverse_inorder(struct Node *node);
void traverse_postorder(struct Node *node);


int main()
{
    struct Node *root = NULL;
    int n, data;
    printf("SPLAY TREE IMPLEMENTATION : ");
    printf("\n----------------------------\n\n");
    
    printf("Enter number of elements : ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        printf("Enter data %d : ", i);
        scanf("%d", &data);
        root = insert(root, data);
    }
    
    printf("\n\nPreorder Traverse : \n");
    traverse_preorder(root);
    printf("\n\nInorder Traverse : \n");
    traverse_inorder(root);
    printf("\n\nPostorder Traverse : \n");
    traverse_postorder(root);
    return 0;
}

struct Node* insert(struct Node* node, int data)
{
    if(node == NULL)
    {
        return new_node(data);
    }
    
    node = splay(node, data);
    
    if(node->data == data)
    {
        return node;
    }
    
    struct Node *newnode = new_node(data);
    
    if(node->data > data)
    {
        newnode->right = node;
        newnode->left = node->left;
        node->left = NULL;
    }
    else
    {
        newnode->left = node;
        newnode->right = node->right;
        node->right = NULL;
    }
    
    return newnode;
}

struct Node* splay(struct Node *node, int data)
{
    if(node == NULL || node->data == data)
    {
        return node;
    }
    
    if(node->data > data)
    {
        if(node->left == NULL)
        {
            return node;
        }
        
        if(node->left->data > data)
        {
            node->left->left = splay(node->left->left, data);
            node = right_rotate(node);
        }
        else if(node->left->data < data)
        {
            node->left->right = splay(node->left->right, data);
            
            if(node->left->right != NULL)
            {
                node->left = left_rotate(node->left);
            }
        }
        
        return (node->left == NULL) ? node : right_rotate(node);
    }
    else
    {
        if(node->right == NULL)
        {
            return node;
        }
        
        if(node->right->data > data)
        {
            node->right->left = splay(node->right->left, data);
            
            if(node->right->left != NULL)
            {
                node->right = right_rotate(node->right);
            }
        }
        else if(node->right->data < data)
        {
            node->right->right = splay(node->right->right, data);
            node = left_rotate(node);
        }
        return (node->right == NULL)? node:left_rotate(node);
    
    }
}

struct Node* new_node(int data)
{
    struct Node *node;
    node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* right_rotate(struct Node *node)
{
    struct Node *temp;
    temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}

struct Node* left_rotate(struct Node *node)
{
    struct Node *temp;
    temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
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