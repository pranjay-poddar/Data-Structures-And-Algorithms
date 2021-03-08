#include <stdio.h>

void binary_search(int a[],int size,int item)
{
    int l=0 ,u= size-1,m;
    while (l <=u)
    {
    m= (l + u)/2;
    if (a[m] == item)
    {
        printf("search successful at index %d",m);
        return;
    }
    else if(a[m] > item )
    {
        u = m - 1;
        
    }
    else 
    {
        l = m + 1;
    
    }
    }
}

int main()
{
    // sorted array 
    int A[10]={2,9,12,15,26,35,44,50,66,78};
     binary_search(A,10,44);
    return 0;
}