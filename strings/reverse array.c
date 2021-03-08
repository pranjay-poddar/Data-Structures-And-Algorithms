#include <stdio.h>
void reverse(int n,int a[]){
    int i;
    for(i = 0;i < n/2;i++){
        int temp = a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }
}
int main()
{
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    reverse(n,a);
    for(i = 0;i < n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
