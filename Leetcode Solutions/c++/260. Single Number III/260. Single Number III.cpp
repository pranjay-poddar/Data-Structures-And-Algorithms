class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xoR = 0,n = nums.size();
        for(int i = 0;i<n;i++) {
            xoR ^= nums[i];
        }
        
        int mask = 1;
        while(1) {
            if((mask & xoR) == 0) {
                mask = mask << 1;
            }
            else break;
        }
        
        int a = 0, b = 0;
        for(int i = 0;i<n;i++) {
            if(nums[i] & mask) a ^= nums[i];
            else b ^= nums[i];
        }
        return {a, b}; 
    }
};