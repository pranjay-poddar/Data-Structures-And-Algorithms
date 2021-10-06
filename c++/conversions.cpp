#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n){
    int temp = 1,ans = 0,lastdigit;
    while(n > 0){
        lastdigit = n % 10;
        ans = ans + temp*lastdigit;
        temp = temp*2;
        n= n/10;
    }
    return ans;
}

int octalToDecimal(int n){
    int sum = 0,temp = 1,lastdigit;
    while (n > 0)
    {
        lastdigit = n % 10;
        sum = sum + temp * lastdigit;
        temp = temp * 8;
        n = n/10;
    }
    return sum ;
}

int hexaToDecimal(string n){
   int base=1,sum = 0;
   int size = n.size();
   for(int i = size - 1; i >= 0;i--){
       if(n[i] >= '0' && n[i] <= '9'){
           sum = sum + base *(n[i]-'0');
       }
       else if(n[i] >= 'A' && n[i] <= 'F'){
           sum = sum + base *(n[i] - 'A' + 10);
       }
          base *= 16;
   }

   return sum;
}

int decimalToBinary(int n){
    int sum = 0,base = 1;
    while(n >= base){
        base = base *2;
    }
    base = base / 2;
    while(base > 0){
        int lastdigit = n/base;
        n = n - base*lastdigit;
        sum = sum*10 +  lastdigit;
        base = base/2;
    }
    return sum ;
}

int decimalToOctal(int n){
    int sum = 0,base = 1,lastdigit;
    while(n>=base){
        base *= 8;
    }
    base/=8;
    while(base > 0){
        lastdigit = n/base;
        n -= base*lastdigit;
        sum = sum *10 + lastdigit;
        base /= 8;
    }
    return sum;
}

string decimalToHexa(int n){
   string sum = "";
   int base = 1,lastdigit;
   while( n >= base){
       base*=16;
   }
   base/=16;

   while(base > 0){
       lastdigit = n/base;
       n -= lastdigit*base;
       base/=16;
       if( lastdigit <= 9){
           sum = sum + to_string(lastdigit);
       }
       else{
           char c = 'A' + lastdigit-10;
           sum.push_back(c);
       }
   }
   return sum;
}

int main(){
    int n;
      string s;
    cin >> n;
    cin >> s;
    cout << "Binary To Decimal:" << binaryToDecimal(n) << endl;
    cout << "Octal To Decimal:" << octalToDecimal(n) << endl;
    cout << "Hexa To Decimal:" << hexaToDecimal(s) << endl;
    cout << "Decimal To Binary:" << decimalToBinary(n) << endl;
    cout << "Decimal To Octal:" << decimalToOctal(n) << endl;
    cout << "Decimal To Hexa:" << decimalToHexa(n) << endl;
return 0;
}