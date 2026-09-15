#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

void random_s(int a[], int n);
void quick_sort(int a[], int p, int q);
int partion(int a[], int p, int r);
void swap(int *a, int *b);

int main()
{
    int a[MAX], n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    printf("Enter %d array elements : ", n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    random_s(a, n);
    quick_sort(a, 0, n-1);
    printf("\nSorted Array : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int a[], int p, int r)
{
    int pivot_index = p + rand()%(r-p+1);
    int pivot;
    int i = p-1;
    int j;
    pivot = a[pivot_index];
    swap(&a[pivot_index], &a[r]);
    for(j=p; j<r; j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[r]);
    return i+1;
}

void quick_sort(int a[], int p, int q)
{
    int j;
    if(p<q)
    {
        j = partion(a, p, q);
        quick_sort(a, p, j-1);
        quick_sort(a, j+1, q);
    }
}

void random_s(int a[], int n)
{
    srand(time(NULL));
    int i, j, temp;
    for(i=n-1; i>0; i--)
    {
        j = rand()%(i+1);
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
