#include <iostream>
using namespace std;

int factorial(int n){
    int fact = n;
    while(n > 1){
      fact = fact * (n-1);
      --n;
    }
    return fact;
}

int main(){
    int n,r,ans;
    cout << "Please enter n, r:";
    cin >> n >> r;
    ans = factorial(n)/(factorial(r)*factorial(n-r));
    cout << ans << endl;     


return 0;
}