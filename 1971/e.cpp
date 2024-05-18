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
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(k), b(k);
    rep(i, k) cin >> a[i];
    rep(i, k) cin >> b[i];

    rep(i, q)
    {
        int d;
        cin >> d;

        auto it = upper_bound(a.begin(), a.end(), d);

        // cerr << "i: " << i << " d: " << d << " it: " << it - a.begin() << endl;

        if (it == a.end())
        {
            cout << b[b.size() - 1] << " ";
        }
        else
        {
            int j = it - a.begin();

            ll dist = a[j];
            ll t = b[j];
            ll base_t = 0;
            if (j >= 1)
            {

                dist -= a[j - 1];
                t -= b[j - 1];
                base_t = b[j - 1];
            }

            // cerr << "j: " << j << " dist: " << dist << " t: " << t << endl;

            cout << base_t + ((ll)t * (d - base_t) / dist) << " ";

            // cerr << endl;
        }
    }
    cout << endl;
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
