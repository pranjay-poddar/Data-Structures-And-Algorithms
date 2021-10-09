#include<iostream>
using namespace std;
int NumberOfOne(int n)
{
    int count=0;
    while (n)
    {
        n=n & (n-1);
        count++;
    }
    return count;
}

int main()
{
    cout<<NumberOfOne(237);
    return 0;
}