#include <bits/stdc++.h>
#define ll long long int
#define debug(x) cout << #x << "=" << x << endl
#define debug2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define PI 3.1415926535897932384626

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    deque<ll> q;
    ll temp;
    cin >> temp;
    q.push_back(temp);
    for (ll i = 1; i < n; i++)
    {
        cin >> temp;
        if (q.front() >= temp)
        {
            q.push_front(temp);
        }
        else
        {
            q.push_back(temp);
        }
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
