class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int c = -999999,flag = 0;
        vector<int> v;
        for(int i= 0;i < nums.size();i++){
            if(nums[i]!=c){
                v.push_back(nums[i]);
                c=nums[i];
            }
        }
        for(int i = 0;i < v.size();i++){
            nums[i] = v[i];
        }
        return v.size();
    }
};