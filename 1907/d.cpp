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

    vector<int> l(n);
    vector<int> r(n);

    rep(i, n)
    {
        cin >> l[i] >> r[i];
    }

    int mx = l[0];
    for (int i = 1; i < n; i++)
    {
        int diff = 0;
        if (l[i] > r[i - 1] && r[i] > r[i - 1])
        {
            diff = r[i - 1] - l[i];
            // cout << l[i] - r[i - 1] << endl;
        }
        else if (l[i] < l[i - 1] && r[i] < l[i - 1])
        {
            diff = l[i - 1] - r[i];
            // cout << l[i - 1] - r[i] << endl;
        }
        else
        {
            // cout << 0 << endl;
        }

        mx = max(mx, diff);
    }

    cout << mx << endl;
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
