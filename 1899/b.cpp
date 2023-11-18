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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i != 0)
            continue;

        // cout << "i=" << i << endl;

        vector<ll> b(n / i);

        for (int j = 0; j < n; j++)
        {
            // cout << "j=" << j << ", j+1/i=" << j / i << endl;
            b[(j) / i] += a[j];
        }

        sort(b.begin(), b.end());

        ans = max(ans, abs(b.front() - b.back()));
    }

    cout << ans << endl;
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
