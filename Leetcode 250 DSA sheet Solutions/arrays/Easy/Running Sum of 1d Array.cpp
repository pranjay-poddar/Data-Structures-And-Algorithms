class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        vector<int> v;
        for(int i = 0; i < nums.size();i++){
            sum+= nums[i];
            v.push_back(sum);
        }
        return v;
    }
};