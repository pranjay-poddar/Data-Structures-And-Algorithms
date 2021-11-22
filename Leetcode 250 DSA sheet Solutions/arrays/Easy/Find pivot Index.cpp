class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long left=0,sum=0;
        int n = nums.size();
         for(int i = 0;i < n;i++){
             sum = sum + nums[i];
         }
        for(int i = 0;i < n;i++){
            sum = sum - nums[i];
            if(sum == left){
                return i;
            }
            left = left +nums[i];
        }
        return -1;
    }
};
