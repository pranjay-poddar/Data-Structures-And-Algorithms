#include <iostream>
using namespace std;
int main()
{
  int n,k,x;
  bool check = false;
  cout<<"Enter size of array, key, segment size\n";
  cin>>n>>x>>k;
  int arr[n];
  cout<<"Enter elements of array\n";
  for(int i = 0; i < n; i++ )
    cin>>arr[i];
  for(int i = 0; i < n ; i++)
  {
    if(arr[i] == x)
      check = true;
    if((i+1)%k == 0 && (i+1) != n)
    {
      if(!check)
        break;
      check = false;
    }
  }
  if(check)
    cout<<"Yes";
  else
    cout<<"No";
}