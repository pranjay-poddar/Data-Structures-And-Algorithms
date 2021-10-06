// binary search recursive method
#include <stdio.h>
int binary_search(int a[],int item,int u,int l)
{
    int m =(u+l)/2;
    if (a[m] == item)
    {
        return m;
    }
    else if (a[m] > item)
    {
        binary_search(a,item,m-1,0);
    }
    else if (a[m] < item)
    {
        binary_search(a,item,u,m+1);
    }
}
int main()
{
    //sorted std::array
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int a = binary_search(arr,4,9,0);    
    printf("%d",a);

    return 0;
}
