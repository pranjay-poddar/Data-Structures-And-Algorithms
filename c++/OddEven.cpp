// C++ program to check for even or odd
// using Bitwise XOR operator
 
#include <iostream>
using namespace std;
 
// Returns true if n is even, else odd
bool isEven(int n)
{
 
    // n^1 is n+1, then even, else odd
    if (n ^ 1 == n + 1)
        return true;
    else
        return false;
}
 
// Driver code
int main()
{
    int n = 100;
    isEven(n)
? cout << "Even"
: cout << "Odd";
 
    return 0;
}
