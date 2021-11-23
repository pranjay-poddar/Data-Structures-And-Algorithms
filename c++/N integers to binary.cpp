#include <bits/stdc++.h> 
#include <math.h>
using namespace std;
long long dtob(int n){ 
    long long sum = 0,base = 1;
    while(n >=base){
        base = base * 2;
        } 
        base = base/2;
        while(base > 0){
            int l = n/base;
            sum = sum *10 + l;
            n = n - l*base;
            base = base/2;
            } 
            return sum ;
    
}
long long power(int b,int n){
    long long s =1;
    for(int i = 1;i <=n;i++){ 
        s = s * b;
        } 
        return s;
    
}

long long btod(int n){
    long long l, temp = 1,ans = 0;
    while(n > 0){
        l = n%10; 
        ans+= temp*l;
        temp = temp *2;
        n = n/10;
        } 
        return ans;
    
}

int main(int argc, char** argv){
    int n;cin>> n;
    long long a[n],b[n],c[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
        
    }
    for(int i = 0 ;i < n;i++){
        b[i]=dtob(a[i]);
        
    }
    for(int i = 1;i <= n;i++){
        c[i-1] = (b[i-1]%power(10,i))/power(10,i-1);
        
    }
    long long s = 0;
    for(int i = n-1;i >=0;i--){
        s= s*10 + c[i];
        
    }
    cout << btod(s);
    
}