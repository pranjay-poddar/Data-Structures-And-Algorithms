#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n){
    int i;
    for(i = 2;i <= sqrt(n);i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int a,b,n,i;
    cout << "Please enter a numbers a and b:";
    cin >> a >> b;
    for(i=a;i<=b;i++){
        if(isprime(i)){
            cout << i << " ";
        }
    }
    cin >> n;

return 0;
}