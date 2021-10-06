#include <iostream>
using namespace std;
int main(){
    int size,pos,i,num;
    cout << "Please enter the size of the array:";
    cin >> size;
    int a[size];
    cout << "Please enter the position to insert a number:";
    cin >> pos;
    cout << "Please enter the number to insert:";
    cin >> num;
    cout << "Please enter the array:";
    for(i = 0; i < size;i++){
        cin >> a[i] ;
    }
    if (pos > size || pos < 0){
        cout << "Invalid position\n";
    }
    else{
        for (i = size -1;i >=pos - 1;i--){
            a[i+1]=a[i];
        }
        a[pos-1]=num;
        size++;
    }
     for(i = 0; i < size;i++){
        cout << a[i] << " ";
    }
    return 0;
}