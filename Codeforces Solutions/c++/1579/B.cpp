#include<bits/stdc++.h>
#define ll long long int
#define debug(x) cout << #x << "=" << x << endl
#define debug2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define PI 3.1415926535897932384626
 
using namespace std;
 
void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	ll b[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	vector<vector<ll>> ans;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			ll j = i + 1;
			while (a[j] != b[i])
			{
				j++;
			}
			vector<int>temp;
			temp.push_back(a[j]);
			for (int k = i; k < j; k++)
			{
				temp.push_back(a[k]);
			}
			for (int k = i; k <= j; k++)
			{
				a[k] = temp[k - i];
			}
			ans.push_back({i + 1, j + 1, j - i});
		}
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << "\n";
	}
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