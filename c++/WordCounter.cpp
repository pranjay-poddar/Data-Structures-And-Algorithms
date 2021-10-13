#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	char str1[] = "Hello, this is a \nWord Counter\n Program  ";
	char *str=str1;
	int state = 0, wc = 0; 
	while (*str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t')
		    state = 0;
		else if (state == 0)
		{
			state = 1;
			++wc;
		}
		++str;
	}
	cout<<"No of words : "<<wc;
	return 0;
}


