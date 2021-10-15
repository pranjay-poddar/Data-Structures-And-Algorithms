/*
Implement a program for stack that performs following operations using array.
(a) PUSH (b) POP (c) PEEP (d) DISPLAY
*/

#include<stdio.h>

int stack[10],item,top=-1,i,n;

void PUSH(void);
void POP(void);
int PEEP(int);
void DISPLAY(void);

int main()
{

int choice,I;

printf("Enter size of our stack: ");
scanf("%d",&n);
printf("\n-----------------------------\n");
printf("\n 1. PUSH \n 2.POP \n 3. PEEP \n 4. DISPLAY \n 5. EXIT");

do
{

printf("\n-----------------------------\n");
printf("\n  Enter your choice: ");
scanf("%d", &choice);
printf("\n-----------------------------\n");


switch(choice)
{
    case 1:
        PUSH();
    break;

    case 2:
        POP();
    break;

    case 3:
        printf("\n Enter element to retrive: ");
        scanf("%d",&I);
        printf("\n I th element from top of the stack is: %d",PEEP(I));
    break;

    case 4:
        DISPLAY();
    break;

    case 5:
        printf("\n EXIT \n");
    break;

    default:
        printf("\n Enter valid choice.");
    break;
}

}while(choice != 5);

return 0;
}

void PUSH()
{
    if (top>=n-1)
    {
        printf("\n stack is Overflow.");
    }
    else
    {
	   printf("\nEnter item to be pushed: ");
	   scanf("%d", &item);
       top++;
       stack[top]=item;
       printf("\n Item to be pushed: %d",item);
    } 
}

void POP()
{
    int itempop;
    if (top==-1)
    {
        printf("\n stack is Underflow.");
    }
    else
    {
        itempop=stack[top];
        top--;
        printf("item is pop= %d",itempop);
    }
}

int PEEP(int I)
{
    if (top-I+1 <= -1)
    
        printf("\n Stack is Underflow on PEEP");
    
    else
        return(stack[top-I+1]);
}

void DISPLAY()
{
    if (top>=0)
    {
        printf("\n stack data: \n");
        for (i = top; i >=0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
    else
    {
        printf("\n Stack is Empty");
    }
}


