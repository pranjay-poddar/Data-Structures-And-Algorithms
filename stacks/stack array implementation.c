//stack array implementation
#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack[N];
int top=-1;

//push function------------------------------------------------
void push()

{
    int n;
    printf("please enter the elemnt that you want to push: ");
    scanf("%d",&n);
    if(top == N-1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack[top]=n;
    }
}

//pop function------------------------------------------------
void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        int item=stack[top];
        printf("Popped element is:%d \n",item);
        top--;
    }
}

//top functions------------------------------------------
void peek()
{
    if(top == -1)
    {
        printf("list is empty!\n");
    }
    else
    {
    printf("The top element is:%d \n",stack[top]);
    }
        
}

//display functions------------------------------------------
void display()
{
    int i;
    for(i = top;i >= 0;i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

//main functions------------------------------------------
int main()
{
    int i,choice;
    do
    {
        printf("Press:\n1 to push an element\n2 to delete element\n3 to get topmost element\n4 to display all elements\n0 to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            
            case 2:
            pop();
            break;
            
            case 3:
            peek();
            break;
            
            case 4:
            display();
            break;
        }
    }
    while(choice);

    return 0;
}
