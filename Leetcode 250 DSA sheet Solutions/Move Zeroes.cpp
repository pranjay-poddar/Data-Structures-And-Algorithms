class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>v;int count = 0,n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[i]!=0){
                v.push_back(nums[i]);
            }
            else{
                count++;
            }
        }
        for(int i = 0;i < n-count;i++){
            nums[i]=v[i];
        }
        int x=n-count;;
        while(count--){
            
            nums[x]=0;
            x++;
        }
    }
};