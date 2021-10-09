
/**
 * This Problem was asked in Geeksforgeeks Interview Series - Paypal interview
 * Problem - You are given an infinite 2-D grid. There are N balloons placed at certain coordinates of the grid. 
 * You have an arrow with yourself, which you will be using to shoot the balloons. 
 * You can select at any point on the grid as your starting point and any point on the grid as the target point.
 * When you fire the arrow, all balloons lying on the shortest path between the starting point and the target point will be burst.
 * Given the coordinates of the N balloons in an array arr, your task is to find out the max number of balloons that you can fire in one arrow shot.
 * Idea -
Balloons can be shoted in x line, y line or an inclined line
row, col, slope, same
row - x same
col - y same
slope - calculate the slop, simplify it, make it to the lowest term by taking gcd and dividing value by gcd and pushing it in the map itself

TestCases -
1.  I/P - N=3, arr={{1,2}, {2,3}, {3,4}}
    O/P - 3
2. I/P - N=3, arr={{2,2}, {0,0}, {1,2}}
    O/P - 2

Time Complexity - O(n^2)
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int mostBalloons(int n, pair<int, int> a[]) {
            if (n <= 2) {
                return n;
            }
            int ans = 2;
            for(int i=0;i<n;i++) {
                map<pair<int, int>, int> slope;
                int same=0,hor=0,ver=0;
                for(int j=0;j<n;j++) {
                    if (i != j) {
                        if (a[i] == a[j]) {
                            same++;
                        } else if (a[i].first == a[j].first) {
                            hor++;
                        } else if (a[i].second == a[j].second) {
                            ver++;
                        } else {
                            int dy = a[i].second - a[j].second;
                            int dx = a[i].first - a[j].first;
                            int g = __gcd(abs(dx), abs(dy));
                            dx /= g;
                            dy /= g;
                            if (dx < 0) {
                                dx *= -1;
                                dy *= -1;
                            }
                            slope[{dy, dx}]++;
                        }
                    }
                }
                ans = max(ans, 1+same+hor);
                ans = max(ans, 1+same+ver);
                for(auto e:slope) {
                    ans = max(ans, 1+same+e.second);
                }
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
        pair<int, int> arr[N];
        for (int i=0;i<N;i++) {
            cin >> arr[i].first;
        }
        for (int i=0;i<N;i++) {
            cin >> arr[i].second;
        }
        Solution obj;
        cout << obj.mostBalloons(N, arr) << endl;
    }
}