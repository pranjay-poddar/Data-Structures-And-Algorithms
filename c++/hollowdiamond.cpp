#include <iostream>
using namespace std;
int main(){
    int i,j,n;
    cout << "Please enter number of rows:";
    cin >> n;
    int space= (2*n-1)/2;
    for(i = 1;i <= n;i++){
    for(j = 1;j <= space;j++){
    cout << " ";
    }
    for(j = 1;j <=2*i-1;j++){
        if(j==1 || j == 2*i -1)
        cout << "*";
        else
        cout << " ";
    }
   
    space--;
    cout << endl;
    }  
    space = 0;
    for(i = 1;i <= n;i++){
         for(j = 1; j <= space;j++){
            cout <<" ";
        }
        for(j = i; j <= 2*n-i;j++){
             if(j==i || j == 2*n-i)
        cout << "*";
        else
        cout << " ";
        }
        
        space++;
    cout << endl;
    }
    
    return 0;
}