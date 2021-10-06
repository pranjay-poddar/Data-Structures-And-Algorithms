#include <iostream>
using namespace std;
int main(){
    int n,num = 2;
    cout << "Please enter the number:";
    cin >> n;
    while( num < n){
    int div = 2;
    while( div < num){
        if(num%div==0){
            num = num + 1;
        }
        else{
            div = div + 1;
        }
    }
    cout << num << " ";
    num= num+1;
    }
    return 0;
}