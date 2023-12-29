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
    // vector<int> a(n), b(n);
    vector<pair<int, int>> ab(n);
    rep(i, n)
    {
        cin >> ab[i].first >> ab[i].second;
    }

    sort(ab.rbegin(), ab.rend());

    vector<int> c;

    int ans = 0;
    rep(i, n)
    {
        int l = lower_bound(c.begin(), c.end(), ab[i].first) - c.begin();
        int r = lower_bound(c.begin(), c.end(), ab[i].second) - c.begin();

        // cout << "a[i]: " << a[i] << ", b[i]: " << b[i] << endl;
        // cout << "l: " << l << ", r: " << r << endl;

        ans += r - l;

        c.emplace_back(ab[i].second);
        sort(c.begin(), c.end());
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
