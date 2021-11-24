#include <iostream>

using namespace std;

int dtob(long n){
    string s = "";
    while(n!=0){
    long mod = n%2;
    s = to_string(mod) + s;
    n = n/2;
    }
    int num = 0;
    for(int i = 0;i < s.size();i++){
        num = num*10 + s[i]-'0'; 
    }
    return num;
}

int main()
{
    long n;
    cin >> n;
    
    cout<<dtob(n);

    return 0;
}

