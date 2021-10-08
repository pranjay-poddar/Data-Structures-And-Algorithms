#include <stdio.h>

int main()
{
    int n ;
    printf("Please enter the size of matrix:");
    scanf("%d",&n);
    int a[n][n],b[n][n],c[n][n],i,j,k;
    printf("Please enter the elements of matrix:");
    for(i = 0;i < n;i++){
        for(j = 0; j < n;j++){
            scanf("%d",&a[i][j]);
        }
    }
     for(i = 0;i < n;i++){
        for(j = 0; j < n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i = 0;i < n;i++){
        for(j = 0; j < n;j++){
            c[i][j]=0;
            for(k = 0; k < n;k++){
                c[i][j] = c[i][j] + a[i][k]*b[k][j]; 
            }
        }
        printf("\n");
    }
    
     for(i = 0;i < n;i++){
        for(j = 0; j < n;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
