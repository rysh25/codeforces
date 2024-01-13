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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n), b(n), c(n - 1);

    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n - 1) cin >> c[i];

    auto W = [&]() -> ll
    {
        // cout << "a: ";
        // rep(i, n) cout << a[i] << " ";
        // cout << endl;
        // cout << "b: ";
        // rep(i, n) cout << b[i] << " ";
        // cout << endl;
        // cout << "c: ";
        // rep(i, n - 1) cout << c[i] << " ";
        // cout << endl;

        ll wine = 0;
        ll water = 0;
        rep(i, n)
        {
            ll w = min(a[i] + water, b[i]);
            wine += w;
            water = max(0LL, a[i] + water - w);

            // cout << "i=" << i + 1 << ", w=" << w << ", water=" << water << endl;
        }

        // cout << "i=" << n << ", w=" << w << ", ret=" << ret << endl;

        return wine;
    };

    ll ans = 0;

    while (q--)
    {
        ll p, x, y, z;
        cin >> p >> x >> y >> z;
        p--;

        a[p] = x;
        b[p] = y;

        if (p != n - 1)
        {
            c[p] = z;
        }
        cout << W() << endl;
    }

    return 0;
}
