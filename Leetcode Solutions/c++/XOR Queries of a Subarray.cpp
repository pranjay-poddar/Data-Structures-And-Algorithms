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