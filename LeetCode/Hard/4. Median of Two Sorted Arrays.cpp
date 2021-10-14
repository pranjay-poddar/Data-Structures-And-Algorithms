// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

/*Suppose the two arrays are A and B.
Perform the following variant of binary search first in A then B to find the median.

Start from low = 0, high = |A|, guess i = floor (low + high)/2
For the median m, there should be total half = floor (|A| + |B| + 1) / 2 elements not greater than it.
Since there are i + 1 elements not greater than A[i] in A,
There should be half - (i + 1) elements not greater than A[i] in B.
Denote j = half - i - 2, thus we can compare if B[j] <= A[i] <= B[j + 1] is satisfied. This indicates
That the guess is the correct median.

Otherwise, we can easily tell if the guess is too small or too big, then halve the elements to adjust
the guess.

Fixes #134
*/

 


//Approach 1

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int n=nums1.size();
        double res;
        if(n&1)
            res=nums1[n/2];
        else if(!(n&1))
            res=(double)(nums1[n/2]+nums1[(n/2)-1])/2;
    
        return res;
            
    }
};


// Approach 2

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size(); 
        int low = 0, high = n1;
        
        while(low <= high) {
            int cut1 = (low+high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1; 
            
        
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1]; 
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2]; 
            
            
            if(left1 <= right2 && left2 <= right1) {
                if( (n1 + n2) % 2 == 0 ) 
                    return (max(left1, left2) + min(right1, right2)) / 2.0; 
                else 
                    return max(left1, left2); 
            }
            else if(left1 > right2) {
                high = cut1 - 1; 
            }
            else {
                low = cut1 + 1; 
            }
        }
        return 0.0; 
    }
};
