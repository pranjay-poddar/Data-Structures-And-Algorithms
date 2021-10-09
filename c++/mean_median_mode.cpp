#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


float Mean(vector<int>X,int N)
{ float mean=0;
   for(auto i =0; i<N; i++)
    {
        mean=mean+X[i];
    }
    return mean/N;
}

float Median(vector<int>X, int N)
{ int mid= (N/2)-1;
    float median=0;
    sort(X.begin(), X.end());
    //if n is even
   if(N%2==0)
   {
   median= ( X[mid] + X[mid+1] )/2.0;
   }
   //if n is odd
   else if(N%2!=0)
    median= X[mid];

return median;
}

int Mode(vector<int>X, int N)
{
    int count=0;
    int freq=0;
    int finalnumber=0;
    int num;
    sort(X.begin(), X.end());
    
    num=X[0];

   for(auto i=0; i<N; i++)
   {
       if(num==X[i])
        { count++;
            if(freq<count)
            {
                finalnumber=X[i];
                freq=count;
            }
        }
        else
        {
            count=0;
            num=X[i];
            count++;
        }
   }

    return finalnumber;
}

int main() {
    vector<int>X;
    int N,data;
    cin>>N;
    for(auto i =0; i<N; i++)
    {
        cin>>data;
        X.push_back(data);
    }
    cout<<fixed<<setprecision(1)<<Mean(X,N)<<endl; 
		//for precision val use setprecision function
    cout<<fixed<<setprecision(1)<<Median(X,N)<<endl;
    cout<<Mode(X,N);
   
    return 0;
}