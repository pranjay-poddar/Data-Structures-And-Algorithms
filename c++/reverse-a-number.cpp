#include <iostream>
using namespace std;

int main(){
    int i,sum = 0,n;
    cout << "Please enter a number:";
    cin >> n;
    while(n!=0){
        i = n%10;
        sum = sum*10 +i;
        n = n/10;
    }
    cout << sum;

return 0;
}