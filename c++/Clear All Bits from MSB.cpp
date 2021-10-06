#include<iostream>
using namepsace std;

int clearBitsMSBThrough(int num, int i) {
    int mask = ( 1 << (i + 1) ) - 1;
    return num & mask;
}

int main(){
  int i,num;
  cout<<"Please enter a number:"<<endl;
  cin>>num;
  cout<<"Enter the value of i:"<<endl;
  cin>>i;
  cout<<endl<<clearBitsMSBThrough(num,i);
  return 0;
}
