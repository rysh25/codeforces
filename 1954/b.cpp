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

    int x = a[0];
    int prev_i = -1;
    int INF = 1e9 + 1;
    int ans = INF;
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i - 1] == x && a[i - 1] == a[i + 1] && a[i] != a[i - 1])
        {
            // cerr << "i: " << i << " "; // debug
            ans = min(ans, i - prev_i - 1);
            prev_i = i;
        }
    }

    // cerr << "prev_i=" << prev_i << endl; // debug

    if (prev_i != -1)
    {
        ans = min(ans, n - 1 - prev_i);
    }

    cout << (ans == INF ? -1 : ans) << endl;
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
