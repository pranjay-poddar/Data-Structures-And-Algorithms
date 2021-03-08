#include <stdio.h>
// bubble sort
void bubble(int a[],int n)
{
    int i,j;
    for (i = 0;i < n - 1 ;i++)
    {
        for(j = 0;j< n - i - 1;j++)
        {
            if (a[j+1]<a[j])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]=temp;
            }
        }
    }
    
}


// insertion sort
void insertion(int a[],int n)
{
    int i,j,temp;
    for(i = 1;i < n;i++)
    {
        temp = a[i];
        for(j = i - 1;j >=0 && temp < a[j];j--)
        {
            a[j + 1] = a [j];
            a[j]=temp;
        }
    }
}


// selection sort
int selection(int a[],int index,int n)
{
    int min=a[index] ,loc=index,i;
    for (i = index + 1;index < n-1;index++)
    {
        if(a[index + 1] < min)
        {
            min = a[index +1];
            loc = index + 1;
        }
    }
   return loc; 
}

int main()
{
    int arrb[5]={5,4,3,1,2};
    int arri[5]={5,4,3,1,2};
    int arrs[5]={5,4,3,1,2};
    int size = 5,i;
    
    bubble(arrb,size);
    insertion(arri,size);
    
    
    for(i = 0;i < size;i++)
    {
     printf("%d ",arrb[i]);
    }
    
    printf("\n");
    
    for(i = 0;i < size;i++)
    {
     printf("%d ",arri[i]);
    }
    
    printf("\n");
    int loc,temp;
    for(i = 0;i <size - 1;i++)
    {
        loc=selection(arrs,i,size);
        temp =arrs[i];
        arrs[i] = arrs[loc];
        arrs[loc] = temp;
    }
    for(i = 0;i < size;i++)
    {
     printf("%d ",arrs[i]);
    }
    
    return 0;
}
