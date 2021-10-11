// 1310. XOR Queries of a Subarray
// Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array containing the result for the given queries.
 
// Example 1:
// Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
// Output: [2,7,14,8] 

// Explanation: 
// The binary representation of the elements in the array are:
// 1 = 0001 
// 3 = 0011 
// 4 = 0100 
// 8 = 1000 
// The XOR values for queries are:
// [0,1] = 1 xor 3 = 2 
// [1,2] = 3 xor 4 = 7 
// [0,3] = 1 xor 3 xor 4 xor 8 = 14 
// [3,3] = 8

// Example 2:
// Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
// Output: [8,0,4,4]

//Solution
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int x=0;
        int prefix[arr.size()];
        for(int i=0;i<arr.size();i++){
            prefix[i]=x^arr[i];
            x=prefix[i];
        }
        vector<int>v;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]>0)
                v.push_back(prefix[queries[i][0]-1]^prefix[queries[i][1]]);
            else
                v.push_back(prefix[queries[i][1]]);
        }
        return v;
    }
};