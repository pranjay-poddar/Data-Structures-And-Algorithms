// 60. Permutation Sequence
// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Example 1:
// Input: n = 3, k = 3
// Output: "213"

// Example 2:
// Input: n = 4, k = 9
// Output: "2314"

// Example 3:
// Input: n = 3, k = 1
// Output: "123"

//Solution
class Solution {
public:
    string getPermutation(int n, int k) {
        if(n==1)
            return "1";
        string ans="";
        for(int i=1;i<=n;i++){
            ans+=to_string(i);
        }
        while(k>1){
            next_permutation(ans.begin(),ans.end());
            k--;
        }
        return ans;
    }
};