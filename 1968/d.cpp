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
    int n, k, pb, ps;

    cin >> n >> k >> pb >> ps;

    pb--, ps--;

    vector<int> a(n), p(n);

    rep(i, n) cin >> p[i], p[i]--;
    rep(i, n) cin >> a[i];

    auto calc = [&](int pos) -> ll
    {
        ll ret = 0;

        int np = pos;
        ll sum = 0;
        for (int i = 0; i < n && i < k; i++)
        {
            ret = max(ret, sum + (ll)a[np] * (k - i));

            sum += (ll)a[np];
            np = p[np];
        }

        return ret;
    };

    ll bs = calc(pb);
    ll ss = calc(ps);

    if (bs > ss)
    {
        cout << "Bodya" << endl;
    }
    else if (bs < ss)
    {
        cout << "Sasha" << endl;
    }
    else
    {
        cout << "Draw" << endl;
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
