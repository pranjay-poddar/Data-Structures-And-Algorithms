/ /merge sort
#include<iostream>
using namespace std;
int pass=1;
int com=0;
void mergeSort(int a[], int left,int mid,int right){

   int i=left,j=mid+1,k=left;
   int arr[right+1];

   while(i<=mid && j<=right){
      if(a[i]<=a[j]){
         arr[k++]=a[i++];
         com++;
      }
      else{
        arr[k++]=a[j++];
        com++;
      }
   }

  while(i<=mid){
     arr[k++]=a[i++];
  }

  while(j<=right){
     arr[k++]=a[j++];
  }

  for(int i=left;i<=right;i++)
    a[i]=arr[i];
}


void mergeSort(int a[],int left,int right){
   if(left>=right)
       return;
   

   int mid=(left+right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);
    mergeSort(a,left,mid,right);
    cout<<"Pass "<<pass<<endl;
       for(int i=left;i<=right;i++)
          cout<<a[i]<<" ";
       cout<<endl;
       cout<<endl;
       pass++;

}

int main(){
  system("clear");
  int n;

  cout<<"Enter no of elements of Array"<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter the elements of Array"<<endl;
  for(int i=0;i<n;i++)
     cin>>a[i];

  mergeSort(a,0,n-1);
  cout<<"The sorted Array is"<<endl;
  for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
  cout<<endl;
 cout<<"Total number of comparisions are "<<com<<endl;
return 0;
}
