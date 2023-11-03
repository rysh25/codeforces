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
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
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
    vector<int> a(2 * n);

    rep(i, 2 * n)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // cout << "a:";
    // rep(i, 2 * n)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    int ans = 0;
    vector<pair<int, int>> p;
    p.emplace_back(a[0], a[n]);
    for (int i = 1; i < n; i++)
    {
        // cout << "i=" << i << ", " << n - 1 + i << endl;
        // cout << "a[i]=" << a[i] << ", a[i -1]=" << a[i - 1] << endl;
        p.emplace_back(a[i], a[n + i]);
        ans += abs(a[i] - a[i - 1]) + abs(a[n + i] - a[n + i - 1]);
    }

    cout << ans << endl;

    for (auto [x, y] : p)
    {
        cout << x << " " << y << endl;
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
