// It sorts like a wave
// if 1st element is higher, than next element is lower, then higher, then lower
// and so on .... vice-versa as well

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];// {1,3,4,2,7,8};
    // sort the array in wave form
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i+=2)
    {

        if(i!=0 && a[i] < a[i-1])
        {
            
            swap(a[i], a[i-1]);
        }
        
        
        if(i!= n-1 && a[i] < a[i+1])
        {
            
            swap(a[i], a[i+1]);
        }
        
        
    }
    
    
    
    for (int i = 0; i < n; i++)
    {
        
        cout << a[i] << "  ";
    }

    return 0;
}
