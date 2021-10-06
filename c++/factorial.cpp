#include <iostream>
using namespace std;

int fact(int n){
    int i=n;
    while(n>1){
        i = i*(n-1);
        --n;
    }
    return i;
}

int main(){
    int n;
    cout << "Please enter a number:";
    cin >> n;
    cout << fact(n) << endl;

return 0;
}