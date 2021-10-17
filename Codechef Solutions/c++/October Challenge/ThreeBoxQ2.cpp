#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<=d and b<=d and c<=d){
    int sum=0;
    sum=(a+b+c);

        if(sum<=d){
        cout<<1<<endl;
    }
    else if(sum>d){
        if((a+b)<=d or (b+c)<=d or (a+c)<=d ){
            cout<<2<<endl;
        }
        else{
            cout<<3<<endl;
        }
    }
    
    
}
    }
}