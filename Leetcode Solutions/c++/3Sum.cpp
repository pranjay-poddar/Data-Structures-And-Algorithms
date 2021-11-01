#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        int n=nums.size();
        int i=0,l=0,r=0,sum=0;
        sort(nums.begin(),nums.end());
        for(i=0;i<n-2;i++){
           
               if( i==0||  nums[i]!=nums[i-1]){
               
            
           l=i+1;
            r=n-1;
        while(l<r){
            sum=nums[i]+nums[l]+nums[r];
           if(sum==0){
               
                vector<int>vt;
               /*vt.push_back(nums[i]);
               vt.push_back(nums[l]);
               vt.push_back(nums[r]);*/
               v.push_back({nums[i],nums[l],nums[r]});
               while(l<r && nums[l]==nums[l+1]) l++;
               while(l<r && nums[r]==nums[r-1]) r--;
               l++;r--;
               //if(i==0) break;
           }else if(sum>0){
               r--;
           }else{
               l++;
           }
        }
               }
        }
      
        return v;
    }
};
