// prime number algorithm 1
#include <stdio.h>
int isprime(int n){
    if(n <=1)return 0;
    if(n==2 || n==3)return 1;
    if(n%2==0 || n%3==0)return 0;
    for(int i=5;i*i<=n;i=i+6){
        if(n%i==0 || n%(i+2)==0)
        return 0;
    }
    return 1;
}
int main()
{
   int i,n;
   printf("Please enter a number to check if it is prime or not:");
   scanf("%d",&n);
   if(isprime(n)){
       printf("Yes\n");
   }
   else{
       printf("No\n");
   }
 return 0;
}
