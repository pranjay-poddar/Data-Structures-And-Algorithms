#include <iostream>
#define N 10
using namespace std;

int top = -1, x;
int stack_arr[N];

void push(int data)
{
    if (top == N - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top = top + 1;
        stack_arr[top] = data;
    }
}

int pop()
{
    int val;
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        val = stack_arr[top];
        top = top - 1;
    }
    return val;
}

void isFull()
{
    if (top == N - 1)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        cout << "Stack is not full" << endl;
    }
}

void isEmpty()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
}

void printdata()
{
    if (top == -1)
    {
        isEmpty();
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stack_arr[i] << " ";
        }
    }
}

int main()
{
    int choice, y;
    while (1)
    {
        cout << "--------------Menu-----------------" << endl;
        cout << "1 push \n"
             << "2 pop \n"
             << "3 isEmpty \n"
             << "4 isFull \n"
             << "5 Print values in stack \n"
             << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to be pushed : ";
            cin >> x;
            push(x);
            break;
        case 2:
            y = pop();
            cout << "The element poped out is : " << y << endl;
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            isFull();
            break;
        case 5:
            printdata();
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}