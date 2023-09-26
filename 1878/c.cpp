#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define endl '\n'

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;

    // cout << "n: " << n << endl;
    // cout << "k: " << k << endl;
    ll min_sum = (k * (k + 1)) / 2;
    ll max_sum = (k * ((2 * (n - k + 1)) + k - 1)) / 2;
    // cout << "min_sum: " << min_sum << endl;
    // cout << "max_sum: " << max_sum << endl;

    if (min_sum <= x && x <= max_sum)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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
