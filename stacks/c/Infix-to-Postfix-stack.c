/*
Implement a program to convert infix notation to postfix notation using stack.
*/

// example

// infix to postfix

// 1	2+3*4	
// ANS	234*+

// 2	A*B+5
// ANS	AB*5+

// 3	(A/(B-C+D))*(E-A)*C
// ANS	ABC-D+/EA-*C*

// 4	X^Y/(5*Z)+2
// ANS	XY^5Z*/2+

// 5	A+B*(C^D-E)^(F+G*H)-I
// ANS	ABCD^E-FGH*+^*+I-

// 6	a+dd^c(3+s)
// ANS	addc3s+^+


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define size 10 
char stack[size];
int top = -1;

void push(char item)
{
	if (top >= size-1)
	{
		printf("\n Stack is Overflow.");
	}
	else
	{
		top++;
		stack[top]=item;
	}
}

char pop()
{
	char item;
	if (top < 0)
	{
		printf("\n Stack is Underflow.");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top];
		top--;
		return(item);
	}
}

int is_operator(char symbol)
{
	if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int precedence(char symbol)
{
	if (symbol == '^')
	{
		return (3);
	}
	else if (symbol == '*' || symbol == '/')
	{
		return (2);
	}
	else if (symbol == '+' || symbol == '-')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void infixtopostfix(char infix_exp[],char postfix_exp[])
{
	int i,j;
	char item,x;

	push('(');
	strcat(infix_exp,")");

	i=0;
	j=0;
	item = infix_exp[i];

	while(item != '\0')
	{
		if (item == '(')
		{
			push(item);
		}
		else if (isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;
			j++;
		}
		else if (is_operator(item) == 1)
		{
			x = pop();
			while(is_operator(x) == 1 && precedence(x) >= precedence(item))
			{
				postfix_exp[j]=x;
				j++;
				x=pop();
			}
			push(x);
			push(item);
		}
		else if (item == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("\n invalid infix expression.");
			getchar();
			exit(1);
		}
		i++;
		item = infix_exp[i];
	}
	if (top > 0)
	{
		printf("\n invalid infix expression.");
		getchar();
		exit(1);
	}
	postfix_exp[j]='\0';

}

int main()
{
	char infix[size],postfix[size];
	printf("\n Enter Infix expression: ");
	gets(infix);

	infixtopostfix(infix,postfix);
	printf("\n Postfix expression: ");
	puts(postfix);

	return 0;
}
