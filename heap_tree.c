#include<stdio.h>
#include<stdlib.h>

void menu();
void operations(int array[], int flag);
void insert_heap(int array[], int data, int flag);
void heapify_max(int array[], int n, int i);
void heapify_min(int array[], int n, int i);
void swap(int *a, int *b);
void print_heap(int array[], int n);
void delete_root(int array[], int data, int flag);

int n = 0;

int main()
{
    menu();
    return 0;
}

void menu()
{
    int heap[20];
    int flag, data, items;
    
    printf("HEAP TREE IMPLEMENTATION : ");
    printf("\n--------------------------\n");
    do
    {
        printf("Choose: \n1. MIN HEAP TREE\n2. MAX HEAP TREE\nChoice : ");
        scanf("%d", &flag);
    }while(flag>2 || flag<0);
    
    if(flag == 1)
    {
        printf("CREATING MIN HEAP TREE...\n");
    }
    else
    {
        printf("CREATING MAX HEAP TREE...\n");
    }
    
    printf("\nEnter number of items : ");
    scanf("%d", &items);
    
    for(int i=1; i<=items; i++)
    {
        printf("Enter Data %d : ", i);
        scanf("%d", &data);
        insert_heap(heap, data, flag);
    }
    operations(heap, flag);
}

void operations(int array[], int flag)
{
    int choice, data;
    printf("\n\nBASIC OPERATIONS : ");
    printf("\n---------------------\n");
    printf("1. SHOW HEAP\n");
    printf("2. INSERT DATA\n");
    printf("3. DELETE DATA\n");
    printf("4. EXIT\n");
    printf("   Choice : ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            print_heap(array, n);
            break;
        case 2:
            printf("Enter Data : ");
            scanf("%d", &data);
            insert_heap(array, data, flag);
            break;
        case 3:
            printf("Enter Data : ");
            scanf("%d", &data);
            delete_root(array, data, flag);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Option!\n");
    }
    operations(array, flag);
}

void insert_heap(int array[], int data, int flag)
{
    if(n == 0)
    {
        array[0] = data;
        n++;
    }
    else
    {
        array[n] = data;
        n++;
        for(int i=(n/2)-1; i>=0; i--)
        {
            if(flag == 1)
            {
                heapify_min(array, n, i);
            }
            else
            {
                heapify_max(array, n, i);
            }
        }
    }
}

void heapify_max(int array[], int n, int i)
{
    if(n > 1)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && array[left] > array[largest])
        {
            largest = left;
        }
        if(right < n && array[right] > array[largest])
        {
            largest = right;
        }
        if(largest != i)
        {
            swap(&array[i], &array[largest]);
            heapify_max(array, n, largest);
        }
    }
}

void heapify_min(int array[], int n, int i)
{
    if(n > 1)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && array[left] < array[smallest])
        {
            smallest = left;
        }
        if(right < n && array[right] < array[smallest])
        {
            smallest = right;
        }
        if(smallest != i)
        {
            swap(&array[i], &array[smallest]);
            heapify_min(array, n, smallest);
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void print_heap(int array[], int n)
{
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void delete_root(int array[], int data, int flag)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(data == array[i])
        {
            break;
        }
    }
    
    swap(&array[i], &array[n-1]);
    n--;
    for(int i=(n/2)-1; i >= 0; i--)
    {
        if(flag == 1)
        {
            heapify_min(array, n, i);
        }
        else
        {
            heapify_max(array, n, i);
        }
    }
}