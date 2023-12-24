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

template <typename T>
T gcd(T a, T b)
{
    if (a < b)
        return gcd(b, a);

    if (b == 0)
        return a;

    T r;
    while ((r = a % b))
    {
        a = b;
        b = r;
    }
    return b;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // vector<ll> diffs;
    // rep(i, n - 1)
    // {
    //     diffs.emplace_back(a[i + 1] - a[i]);
    // }
    // cout << "diffs:";
    // for (ll diff : diffs)
    // {
    //     cout << " " << diff;
    // }
    // cout << endl;

    ll g = a[0];
    rep(i, n - 1)
    {
        g = gcd(g, a[i + 1]);
    }
    // cout << "g=" << g << endl;

    // rep(i, n)
    // {
    //     a[i] /= g;
    //     // cout << a[i] << " ";
    // }
    // cout << endl;

    auto is_ok = [&](ll d) -> bool
    {
        // cout << "d=" << d << endl;
        set<ll> mods;
        for (ll value : a)
        {
            mods.insert(value % d);
            if (mods.size() > 2)
            {
                return false;
            }
        }
        // cout << "d=" << d << ", mods.size()=" << mods.size() << endl;
        // cout << "mods.size()=" << mods.size() << endl;
        if (mods.size() == 2)
        {
            return true;
        }

        return false;
    };

    // for (ll i = 1; i * i < 1e18 + 1; i++)
    // {
    //     if (is_ok(i))
    //     {
    //         cout << i << endl;
    //         return;
    //     }
    // }

    int ans = -1;
    for (ll i = g + (1 * g); i < 1e18 + 1; i *= 2)
    {
        if (is_ok(i))
        {
            ans = i;
            cout << ans << endl;
            break;
        }
    }
    // if (is_ok(2 * g + 1))
    // {
    //     cout << 2 * g + 1 << endl;
    // }
    // else if (is_ok(a.back() + 1))
    // {
    //     cout << a.back() + 1 << endl;
    // }
    // else
    // {
    //     cout << -1 << endl;
    // }

    // cout << "mod:";
    // rep(i, n)
    // {
    //     cout << a[i] % ans << " ";
    // }
    // cout << endl;
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
