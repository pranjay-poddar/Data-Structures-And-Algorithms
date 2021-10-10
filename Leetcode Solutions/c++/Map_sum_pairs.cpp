//link(https://leetcode.com/problems/map-sum-pairs/) 
class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key]=val;
    }
    
    int sum(string prefix) {
        int sum=0;
        for(auto i:mp)
        {
            if(i.first.substr(0,prefix.size())==prefix)
                 sum+=i.second;
        }
      return sum;  
    }
};