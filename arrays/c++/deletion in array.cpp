#include <iostream>
using namespace std;
int main(){
    int size,pos,i,num;
    cout << "Please enter the size of the array:";
    cin >> size;
    int a[size];
    cout << "Please enter the position to delete a number:";
    cin >> pos;
    cout << "Please enter the array:";
    for(i = 0; i < size;i++){
        cin >> a[i] ;
    }
    if (pos > size || pos < 0){
        cout << "Invalid position\n";
    }
    else{
        for (i = pos - 1;i < size - 1;i++){
            a[i]=a[i+1];
        }
        size--;
        for(i = 0; i < size;i++){
        cout << a[i] << " ";
    }
    }
     
    return 0;
}