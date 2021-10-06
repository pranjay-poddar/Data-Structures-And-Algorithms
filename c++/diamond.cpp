#include<iostream>
using namespace std;
int main(){

int i,j,r;
cout << "Please enter number of rows:";
cin >> r;
for(i=1;i<=2*r;i++){
    if(i <=r){
for(j=1;j <= r-i;j++){
cout << " ";
}
for(;j<=r;j++){
    cout << "*";
}
for(;j <r+i;j++){
    cout << "*";
}
for(;j <2*r;j++){
    cout << " ";
}
}
else{
    if(i!=2*r){
for(j=1;j<(i%r);j++){
cout << " ";
}
for(;j <=r;j++){
    cout << "*";
}
for(;j <=2*r-(i%r);j++){
    cout << "*";
}
for(;j < (i%r);j++){
    cout << "m";
}
}
else{
    for(j=1;j<r;j++){
        cout << " ";
    }
    for(;j <r+1;j++){
        cout << "*";
    }
    for(;j <2*r;j++){
        cout << " ";
    }
}
}

cout<<endl;
}
return 0;
}