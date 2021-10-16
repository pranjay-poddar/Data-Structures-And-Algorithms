#include <stdio.h>
#include <conio.h>
int reverse(int num);
int p_d(int num);
int main()
{
    int num;
    printf("Number:");
    scanf("%d", &num);
    if(p_d(num) == 1)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
    return 0;
}
int p_d(int num)
{
    if(num == reverse(num))
    {
        return 1;
    }
    return 0;
}
int reverse(int num)
{
    int rem;
    static int sum=0;
    if(num!=0){
            rem=num%10;
            sum=sum*10+rem;
            reverse(num/10);
    }
        else
            return sum;
    return sum;
} 
