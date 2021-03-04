//left rotation of array
#include <stdio.h>
void onerotate(int a[],int n,int k);
void rotate(int a[],int n,int k){
    int i,j;
    for(i = 0;i < k;i++){
        onerotate(a,n,k);
    }
}
void onerotate(int a[],int n,int k){
    int i,j,temp=a[0];
    
    for(i = 0;i < n-1;i++){
        a[i]=a[i+1];
    }
    a[n-1]=temp;
     
}
void printa(int a[],int n){
    int i;
    for(i = 0 ;i < n;i++){
        printf("%d ",a[i]);
    }
}
int main()
{
    int i,n,k;
    printf("Please enter number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Please enter elements:");
    for(i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter number of left shifts:");
    scanf("%d",&k);
    rotate(a,n,k);
    printa(a,n);
    return 0;
}
