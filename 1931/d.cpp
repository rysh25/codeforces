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
    int n, x, y;
    cin >> n >> x >> y;

    // cout << "n=" << n << ", x=" << x << ", y=" << y << endl; // debug

    vector<int> a(n);

    rep(i, n)
    {
        cin >> a[i];
    }
    map<pair<int, int>, int> remains_count;

    rep(i, n)
    {
        // cout << a[i] << " ";
        pair<int, int> p = make_pair(a[i] % x, a[i] % y);
        remains_count[p]++;
    }

    // cout << endl;

    // cout << "remains_count:" << endl;
    // for (auto &p : remains_count)
    // {
    //     cout << "(" << p.first.first << " " << p.first.second << ") " << p.second << endl;
    // }
    // cout << endl;

    int ans = 0;
    for (auto &p : remains_count)
    {
        cout << "p: " << p.first.first << " " << p.first.second << " " << p.second << endl;
        if (p.first.first == 0)
        {
            if (p.second > 1)
            {
                cout << "1: " << p.second << endl;
                ans += p.second * (p.second - 1);
            }
        }
        else if (p.second > 0 && p.first.first > 0)
        {
            if (remains_count[make_pair(x - p.first.first, p.first.second)] > 0)
            {
                cout << "2: " << p.second << " " << remains_count[make_pair(x - p.first.first, p.first.second)] << endl;
                ans += p.second * remains_count[make_pair(x - p.first.first, p.first.second)];
            }
        }
    }

    cout << ans / 2 << endl;
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
