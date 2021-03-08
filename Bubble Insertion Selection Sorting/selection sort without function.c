selection sort

#include <stdio.h>
int main()
{
    int min,i,j,loc,temp,n = 10,a[10]={9,8,7,6,5,4,3,2,1,13};
    for (i = 0;i < n-1;i++)
    {
        loc = i;
        min = a[i];
        for (j = i + 1;j < n;j++)
        {
            if (a[j] < min)
            {
                loc = j;
                min = a[j];
            }
        }
        
        if (loc != i)
        {
            temp = a[i];
            a[i] = a[loc];
            a[loc] = temp;
        }
    }
    for (i = 0; i <n ;i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;
}