//quick sort as first element as pivot
#include<iostream>
using namespace std;
 int partitionLowPivot(int a[],int low,int high){

   int pivot=a[low];
   int left=low;
   int right=high+1;

   while(left<right){
      
        do{
			left++;
		}while(left<=high && a[left]<pivot);
		
		
		do{
			right--;
		}while(a[right]>pivot);   
      

      if(left<right){
         int temp=a[left];
         a[left]=a[right];
         a[right]=temp;
      }
   }
 
   
   int temp=a[low];
   a[low]=a[right];
   a[right]=temp;
  
   
   return right;
 }

  void quickSort(int a[],int low,int high){
     if(low<high){
       int j=partitionLowPivot(a,low,high);
        quickSort(a,low,j-1);
        quickSort(a,j+1,high);
        
     }
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
  
  quickSort(a,0,n-1);
  cout<<"Array after Sorting"<<endl;
  for(int i=0;i<n;i++)
   cout<<a[i]<<" ";
  cout<<endl;
 return 0;
} 
