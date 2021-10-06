#include <iostream>
using namespace std;
int main(){
    int i,j,n;
    cout << "Please enter number of rows:";
    cin >> n;
    int space=(2*n-1)/2;
    int count;
    for(i = 1;i <= n;i++){
        count =1 ;
        for(j = 1;j<=space;j++){
            cout << " ";
        }
        for(j=1;j <=i;j++){
            cout << count << " " ;
            count++;
        }
        space--;
        cout << endl;
    }
}