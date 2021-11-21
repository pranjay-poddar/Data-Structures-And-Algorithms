#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void merge(int a[],int lb,int mid,int ub){
    int i = lb,j = mid+1,k = lb;
    int b[ub - lb + 1];
    while(i <= mid && j <=ub){
        if(a[i] <= a[j]){
            b[k] = a[i];
            i++;
            k++;
        }
        else{
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if(i > mid){
        while(j <= ub){
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else{
        while(i <= mid){
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for(int i = lb; i <= ub;i++){
        a[i]=b[i];
    }
}

void mergesort(int a[],int lb,int ub){
    if(lb < ub){
        int mid = (lb + ub)/2;
       mergesort(a,lb,mid); 
       mergesort(a,mid+1,ub);
       merge(a,lb,mid,ub);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    mergesort(a,0,9);
    for(int i = 0;i < n;i++){
        cout << a[i] << " ";
    }
    return 0;
}

