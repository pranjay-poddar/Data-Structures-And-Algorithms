#include<bits/stdc++.h>
#define ll long long int
#define debug(x) cout << #x << "=" << x << endl
#define debug2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define PI 3.1415926535897932384626
 
using namespace std;
 
void solve()
{
	string s;
	cin >> s;
	ll n = s.size();
	if (n % 2)
	{
		cout << "NO";
	}
	else
	{
		ll ans = 0;
		for (auto i : s)
		{
			if (i == 'A') ans++;
			else if (i == 'B') ans--;
			else ans++;
		}
		if (ans)
		{
			cout << "NO";
		}
		else
		{
			cout << "YES";
		}
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

	ll t;   cin >> t;   while (t--)
	{
		solve();
	}
}