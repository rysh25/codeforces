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
    rep(i, n)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int l = 1, r = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[0] == a[i])
        {
            l++;
        }
        else
        {
            break;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[n - 1] == a[i])
        {
            r++;
        }
        else
        {
            break;
        }
    }

    // cout << "l=" << l << ", r=" << r << endl; // debug

    if (a[0] == a[n - 1])
    {
        cout << n - min(l + r, n) << endl;
        return;
    }
    else
    {
        cout << n - max(l, r) << endl;
        return;
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
