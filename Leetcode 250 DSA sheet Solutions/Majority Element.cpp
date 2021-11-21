class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i = 0 ; i < nums.size();i++){
            m[nums[i]]++;
        }
        int mx = 0;
        int index=0;
        for(unordered_map<int,int> :: iterator i = m.begin();i!=m.end();i++){
         if(mx < i->second){
             mx = i->second;
             index = i->first;
         }
        }
    return index;
    }   
};