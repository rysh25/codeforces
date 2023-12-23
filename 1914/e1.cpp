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
    // cout << "n=" << n << endl;
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    vector<pair<int, int>> x;
    rep(i, n)
    {
        if (a[i] > 0 && b[i] > 0)
        {
            // cout << "a[i]=" << a[i] << ", b[i]=" << b[i] << endl;
            x.push_back(make_pair(-(a[i] + b[i]), i));
        }
    }

    sort(x.begin(), x.end());

    cout << "x.size()=" << x.size() << endl;
    rep(i, x.size())
    {
        cout << "x[" << i << "]=" << x[i].first << ", " << x[i].second << endl;
    }
    cout << endl;

    ll ans = 0;
    bool even = x.size() % 2 == 0;

    cout << "a: ";
    rep(i, n)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    rep(i, x.size())
    {
        cout << "i=" << i << ", x[i].second=" << x[i].second << endl;
        ans += a[x[i].second] - 1;
        cout << "a[i]=" << a[i] << ", ans=" << ans << endl;
        if (i == x.size() / 2 && !even)
            break;
        ans -= b[x[n - i - 1].second] + 1;
        cout << "b[i]=" << b[x[n - i - 1].second] << ", ans=" << ans << endl;
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
