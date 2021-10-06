#include<stdio.h>
int main()
{
    int a;
    printf("enter a year\n");
    scanf("%d",&a);

    if (a%4==0 || a%100==0 || a%400==0)
    
        printf("%d is a leap year",a);
        else
        printf("%d is not leap year",a);
        return 0;


    
    
}
