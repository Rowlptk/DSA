#include<stdio.h>
#define MAX 100

void merge_sort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);

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
    
    merge_sort(a, 0, n-1);
    
    printf("\nSorted Array: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    
}


void merge(int a[], int l, int m, int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    
    int a1[n1], a2[n2];
    
    for(int i=0; i<n1; i++)
    {
        a1[i] = a[l+i];
    }
    for(int i=0; i<n2; i++)
    {
        a2[i] = a[m+1+i];
    }
    
    int i=0, j=0, k=l;
    
    while(i<n1 && j<n2)
    {
        if(a1[i] <= a2[j])
        {
            a[k] = a1[i];
            i++;
        }
        else
        {
            a[k] = a2[j];
            j++;
        }
        k++;
    }
    
    while(i<n1)
    {
        a[k] = a1[i];
        i++;
        k++;
    }
    
    while(j<n2)
    {
        a[k] = a2[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int l, int r)
{
    if(l<r)
    {
        int m = l+(r-l)/2;
        
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        
        merge(a, l, m, r);
    }
}