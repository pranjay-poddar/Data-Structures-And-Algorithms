#include <iostream>
#include <cmath>
using namespace std;
int main(){
int i,j,n;
cout << "Please enter a number:";
cin >> n;
int flag = 0;
for(i = 2;i <= sqrt(n);i++){
    if(n%i==0){
        cout << " Non-Prime" <<endl;
        flag = 1;
        break;
    }
}
if(flag == 0){
    cout << "Prime" << endl;
}
    return 0;
}