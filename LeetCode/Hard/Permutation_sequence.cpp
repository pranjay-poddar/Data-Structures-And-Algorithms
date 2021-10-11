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