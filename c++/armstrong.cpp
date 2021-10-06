#include <iostream>
using namespace std;

int main(){
    int i,j,n,t,sum = 0;
    cout << "Please enter a number:";
    cin >> n;
    t = n;
    while(n > 0){
        i = n % 10;
        j = i*i*i;
        sum = sum + j;
        n = n/10;
    }
    if(t == sum)
    cout << sum << " is an Armstrong Number" << endl;
    else
    cout << "Not An Armstrong Number" << endl;

return 0;
}