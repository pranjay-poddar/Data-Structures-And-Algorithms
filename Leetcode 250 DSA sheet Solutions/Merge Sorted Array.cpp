class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int b[m+n];
        int k = 0;
        int i= 0,mid1 = m-1,j=0,mid2 = n-1;
        while(i <= mid1 && j <= mid2){
            if(nums1[i] < nums2[j]){
                b[k]=nums1[i];
                i++;
                k++;
            }
            else{
                b[k]=nums2[j];
                j++;
                k++;
            }
        }
        if(i > mid1){
            while(j <= mid2){
                b[k]=nums2[j];
                j++;
                k++;
            }
        }
        else{
            while(i <= mid1){
                b[k]=nums1[i];
                i++;
                k++;
            }
        }
        for(int z = 0;z < m+n;z++){
            nums1[z]=b[z];
        }
    }
};