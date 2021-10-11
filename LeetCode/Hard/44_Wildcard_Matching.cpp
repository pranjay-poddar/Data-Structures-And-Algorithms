/*Given an input string (s) and a pattern (p), implement wildcard 
pattern matching with support for '?' and '*' 
where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 */


class Solution {
    vector<vector<int>> t;
public:
    bool solve(string& s, string& p, int n, int m){
        
        // Base case
        // p = 0; s = 0;
        if(n < 0 and m < 0){
            return true;
        }
        
        // P = 0
        if(m < 0){
            return 0;
        }
        
        // s = 0 -- But also matches the null string
        if( n < 0){
            while(m >= 0){
                if(p[m] != '*'){
                    return false;
                }
                m--;
            }
            return 1;
        }
        
        if(t[n][m] != -1){
            return t[n][m];
        }
        
        // -------------- Recursive case --------------
        if(p[m] == '*'){
            return t[n][m] = solve(s, p, n-1, m) || solve(s, p, n, m-1);
        }
        
        else{
            if(s[n] != p[m] and p[m] != '?'){
                return t[n][m] = 0;
            }
            else{
                return t[n][m] = solve(s, p, n-1, m-1);
            }
        }
        return t[n][m];
    }
    
    bool isMatch(string s, string p) {
        // memset(t, -1, sizeof(t));
        t.clear();
        t.resize(s.size()+1, vector<int>(p.size()+1, -1));
        
        return solve(s, p, s.size()-1, p.size()-1);
    }
};
