// Q) There are three people, and each of them has an unbiased 6-sided
// die. The result of rolling a die will be a number between 1 and 
// 6 (inclusive) with equal probability.

// The three people throw their dice simultaneously. In this game, the
// third person wins only if his number is strictly greater than 
// the sum of the other two numbers. Given that the first person 
// rolls the value X and the second person rolls the value Y, what 
// is the probability the third person will win?

// Input Format
// The first line contains an integer T, the number of test cases. Then the test cases follow.
// Each test case contains two integers X and Y.
// Output Format
// For each test case, output the probability that the third person wins.

// Your answer will be considered correct if its absolute error 
// doesn't exceed 10−6.

// Constraints
// 1≤T≤36
// 1≤X,Y≤6
// Sample Input 1 
// 3
// 1 3
// 2 4
// 2 3
// Sample Output 1 
// 0.333333
// 0
// 0.166666

// Solution ->
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, x, y;
    // testcase input
    cin>>t;
    
    while(t--){
        float res;
        // taking inputs
        cin>>x>>y;
        
        int sum = (x+y);

        // condition checking
        if(sum < 6){
            cout<<((float)(6-sum)/6)<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}