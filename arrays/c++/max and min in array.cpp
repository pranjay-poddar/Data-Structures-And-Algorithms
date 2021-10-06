#include <iostream>
using namespace std;
struct p{
    int max;
    int min;
};

struct p compare(int a[],int n){
    int i;
    struct p num;
    if(n == 1){
        num.max=a[0];
        num.min=a[0];
        return num;
    }
    if(n > 1){
        if(a[0]>a[1]){
            num.max=a[0];
            num.min=a[1];
        }
        else{
            num.max=a[1];
            num.min=a[0];
        }
        for(i = 2;i < n;i++){
            if(a[i]>num.max){
                num.max=a[i];
            }
            if(a[i]<num.min){
                num.min=a[i];
            }
        }
    }
    return num;
}
int main(){
    int i,n;
    cout << "Please Enter size of array:";
    cin >> n;
    int a[n];
    cout << "Please Enter elements of the array:";
    for(i = 0; i < n;i++){
        cin >> a[i];
    }
    struct p c;
    c=compare(a,n);
    cout << " maximum:" << c.max << endl;
    cout << " minimum:" << c.min << endl;
    
    return 0;
}