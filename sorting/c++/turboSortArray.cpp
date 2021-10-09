// Turbo Sort Array Program In C++
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, item;
    cin>>n;
    // declaring a vector of integer type
    vector<int> vect;
    
    // using for loop elements elements to the vector using its push_back method
    for(int i=0; i<n; i++){
        cin>>item;
        vect.push_back(item);
    }
    
    // calling the sort() method that in-place sorts the vector elements and doesn't return anything
    sort(vect.begin(), vect.end());
    
    // displaying the sorted vector elements
    for(auto i:vect){
        cout<<i<<" ";
    }
    return 0;
}
