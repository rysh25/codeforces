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
    ll k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    int l = 0, r = n - 1;

    int ans = 0;

    while (k > 0 && l <= r)
    {
        // cout << "l: " << l << " r: " << r << " k: " << k << endl;
        int x = min(a[l], a[r]);

        // if (x == 0)
        //     break;
        // cout << "a[l]: " << a[l] << " a[r]: " << a[r] << " x: " << x << endl;

        if (x * 2 > k)
        {
            int y = min((ll)x, (k + 1) / 2);
            a[l] -= y;
            k -= y;
        }
        else
        {
            a[l] -= x;
            k -= x;
        }

        if (a[l] == 0)
        {
            ans++;
            l++;
        }

        if (k <= 0 || l > r)
            break;

        a[r] -= min((ll)x, k);
        k -= min((ll)x, k);

        if (a[r] == 0)
        {
            ans++;
            r--;
        }
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
