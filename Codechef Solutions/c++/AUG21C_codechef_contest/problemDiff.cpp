// Q) You have prepared four problems. The difficulty levels of the problems are A1,A2,A3,A4 respectively. 
// A problem set comprises at least two problems and no two problems in a problem set should have the same difficulty level. 
// A problem can belong to at most one problem set. Output the maximum number of problem sets you can create using the four problems.

// Input Format
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first and only line of each test case contains four space-separated integers A1, A2, A3, A4, difficulty levels of the four problems.
// Output Format
// For each test case, print a single line containing one integer - the maximum number of problem sets you can create using the four problems.

// Constraints
// 1≤T≤1000
// 1≤A1,A2,A3,A4≤10
// Subtasks
// Subtask #1 (100 points): Original constraints

// Sample Input 1 
// 3
// 1 4 3 2
// 4 5 5 5
// 2 2 2 2
// Sample Output 1 
// 2
// 1
// 0

// Solution->
#include <bits/stdc++.h>
#define MAX 4
using namespace std;

void findProblemDiff(int *arr) {
    // three possible cases checking
    if(arr[0]==arr[1] && arr[1]==arr[2] && arr[2]==arr[3]){
        cout<<0<<endl;
    } else if((arr[0]==arr[1] && arr[1]==arr[2]) || (arr[1]==arr[2] && arr[2]==arr[3])){
        cout<<1<<endl;
    } else{
        cout<<2<<endl;
    }
}

int main() {
        // as the number of elements to be considered is fixed according to this problem so I have taken a array of constant size of 4
	int t,a[MAX];
	cin>>t;	

	while(t--){
            // taking array input
	    for(int i=0; i<MAX; i++){
	        cin>>a[i];
	    }
	    
            // sorting the array
	    sort(a,a+MAX);
	    
	    // calling the function to find out the problem difference
	    findProblemDiff(a);
	}
	return 0;
}
