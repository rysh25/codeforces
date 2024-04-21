#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <utility>
#include <string>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstring>
// #include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <tuple>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

#define endl '\n'

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

void solve()
{
    ll MOD = 1e9 + 7;

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);

    rep(i, n)
    {
        cin >> a[i];
    }

    ll sum = 0;
    rep(i, n)
    {
        sum += a[i];
    }

    // cout << ((sum % MOD) + MOD) % MOD << endl;

    vector<ll> dp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = max(a[i], dp[i] + a[i]);
    }

    ll mx = *max_element(dp.begin(), dp.end());

    ll r = sum - mx;

    // cout << "mx: " << mx << endl;

    ll ans = sum;

    ll add = mx;
    rep(i, k)
    {
        ans = (ans + add) % MOD;
        add = add * 2 % MOD;
    }

    cout << ((ans % MOD) + MOD) % MOD << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
