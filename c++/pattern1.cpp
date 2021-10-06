#include <iostream>
using namespace std;
int main(){
    int i,j,n;
    cout << "Please enter rows:";
    cin >> n ;
    int count;
    int num;
    for(i=1;i <= n;i++){
        count = 6;
        num = 1;
        for(j = 1;j < 2*n;j++){
            count --;
            
            if(j >=1 && j <= n-i) {
            cout <<" ";
           
            }
            else if(j <= n){
            cout << count ;
            }
         
            else if(j>5 && j <n+i && i > 1){
            num++;
            cout << num ;
            }
        
         
            
        }
        
        
        cout << endl;
      
    }
    return 0;

}