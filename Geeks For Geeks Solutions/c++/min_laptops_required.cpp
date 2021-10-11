"""
This problem was asked recently in Geeksforgeeks Interview Series Morgan Stanley
Problem -   There are N jobs and the start and finish time of the jobs are given in start[] and end[] respectively. 
            Each job requires one laptop and laptops can't be shared. 
            Find the minimum number of laptops required given that you can give your laptop to someone else when you are not doing your job.

Idea - Difference Array and Coordinates compression technique is used here

Test Cases -
1.  I/P -   N=3, start[] = {1,2,3}, end[] = {4,4,6}
    O/P -   3

2.  I/P -   N=3, start[] = {1,5,2}, end[] = {2,6,3}
    O/P -   1

Time Complexity - O(nLogn)

"""



#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minLaptops(int n, int s[], int e[]) {
            map<int, int>m;
            // initialization of start and end time
            for (int i=0;i<n;i++) {
                m[s[i]];
                m[e[i]];
            }
            int id = 0;
            // assigning index values
            for (auto &e: m) {
                e.second = id++;
            }
            vector<int>v(id+1, 0);

            // adding 1 to start time and -1 to end time
            for (int i=0;i<n;i++) {
                v[m[s[i]]]++;
                v[m[e[i]]]--;
            }
            for (int i=1;i<=id;i++){
                v[i] = v[i-1]+v[i];
            }
            int ans = 0;
            for (auto e: v) {
                ans = max(ans, e);
            }
            return ans;
        }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for (int i=0;i<N;i++) {
            cin >> start[i];
        }
        for (int i=0;i<N;i++) {
            cin >> end[i];
        }

        Solution obj;
        cout << obj.minLaptops(N, start, end) << endl;
    }
    return 0;
}