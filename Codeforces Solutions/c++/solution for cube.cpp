#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define all(a) a.begin(), a.end()
#define x first
#define y second
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
int arr[25];
bool eq(int a, int b, int c, int d)
{
    if (arr[a] == arr[b] && arr[c] == arr[d] && arr[a] == arr[c])
        return 1;
    else
        return 0;
}
bool check1()
{
    bool f1 = 0, f2 = 0, f3 = 0,f4 = 0,f5 = 0,f6 = 0;
    if (eq(3, 4, 13,15))
        f1 = 1;
    if (eq(1,2,17,19))
        f2 = 1;
    if (eq(9,10,18,20))
        f3 = 1;
    if (eq(11,12,14,16))
        f4 = 1;
    if (eq(5,6,7,8))
        f5 = 1;
    if (eq(21,22,23,24))
        f6 = 1;
    return (f1 & f2 & f3 & f4 & f5 & f6);
}

bool check6()
{
    bool f1 = 0, f2 = 0, f3 = 0,f4 = 0,f5 = 0,f6 = 0;
    if (eq(3, 4, 18,20))
        f1 = 1;
    if (eq(1,2,14,16))
        f2 = 1;
    if (eq(9,10,13,15))
        f3 = 1;
    if (eq(11,12,17,19))
        f4 = 1;
    if (eq(5,6,7,8))
        f5 = 1;
    if (eq(21,22,23,24))
        f6 = 1;
    return (f1 & f2 & f3 & f4 & f5 & f6);
}
bool check2()
{
    bool f1 = 0, f2 = 0, f3 = 0,f4 = 0,f5 = 0,f6 = 0;
    if (eq(13, 14, 15, 16))
        f1 = 1;
    if (eq(17, 18, 19, 20))
        f2 = 1;
    if (eq(1,3,6,8))
        f3 = 1;
    if (eq(5,7,10,12))
        f4 = 1;
    if (eq(2,4,22,24))
        f5 = 1;
    if (eq(9,11,21,23))
        f6 = 1;
    return (f1 & f2 & f3 & f4 & f5 & f6);
}

bool check5()
{
    bool f1 = 0, f2 = 0, f3 = 0,f4 = 0,f5 = 0,f6 = 0;
    if (eq(13, 14, 15, 16))
        f1 = 1;
    if (eq(17, 18, 19, 20))
        f2 = 1;
    if (eq(1,3,21,23))
        f3 = 1;
    if (eq(22,24,10,12))
        f4 = 1;
    if (eq(2,4,5,7))
        f5 = 1;
    if (eq(6,8,9,11))
        f6 = 1;
    return (f1 & f2 & f3 & f4 & f5 & f6);
}
bool check3()
{
    bool f1 = 0, f2 = 0, f3 = 0,f4 = 0,f5 = 0,f6 = 0;
    if (eq(9,10,11,12))
        f1 = 1;
    if (eq(5,6,15,16))
        f2 = 1;
    if (eq(19,20,21,22))
        f3 = 1;
    if (eq(13,14,23,24))
        f4 = 1;
    if (eq(7,8,17,18))
        f5 = 1;
    if (eq(1,2,3,4))
        f6 = 1;
    return (f1 & f2 & f3 & f4 & f5 & f6);
}
bool check4()
{
    bool f1 = 0, f2 = 0, f3 = 0,f4 = 0,f5 = 0,f6 = 0;
    if (eq(1,2,3,4))
        f1 = 1;
    if (eq(15,16,21,22))
        f2 = 1;
    if (eq(7,8,13,14))
        f3 = 1;
    if (eq(9,10,11,12))
        f4 = 1;
    if (eq(5,6,19,20))
        f5 = 1;
    if (eq(17,18,23,24))
        f6 = 1;
    return (f1 & f2 & f3 & f4 & f5 & f6);
}


int main()
{
    // your code goes here
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 24; i++)
        cin >> arr[i];
    if (check1() || check2() || check3() || check4() || check5() || check6())
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

