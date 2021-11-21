class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // unordered_map<int, int> data;
        // for (int i = 0; i < nums.size(); ++i) {
        //     data.emplace(nums[i], i);
        //     int needed_num = target - nums[i];
        //     if (data.find(needed_num) != data.end() && data[needed_num] != i) {
        //         return {i, data[needed_num]};
        //     }
        // }
        // return {};

// sol1-----------------------------^^
        
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            int y = target - nums[i];
            if(m.find(y)!=m.end()){
                return {i,m[y]};
            }
            else{
                m[nums[i]]=i;
            }
        }
        return {};
    }
    
};