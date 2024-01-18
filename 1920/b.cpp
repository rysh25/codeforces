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
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> prefix_sum(n + 1);
    vector<int> suffix_sum(n + 1);
    prefix_sum[0] = 0;
    suffix_sum[n] = 0;
    rep(i, n)
    {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
        suffix_sum[n - i - 1] = suffix_sum[n - i] + a[n - i - 1];
    }

    // cout << "prefix_sum: ";
    // rep(i, n + 1)
    // {
    //     cout << prefix_sum[i] << " ";
    // }
    // cout << endl;

    // cout << "suffix_sum: ";
    // rep(i, n + 1)
    // {
    //     cout << suffix_sum[i] << " ";
    // }
    // cout << endl;

    int INF = 1e9 + 1;
    int ans = -INF;
    // cout << "**k=" << k << endl;
    rep(i, k + 1)
    {
        // cout << "i=" << i << ", x=" << x << ", n=" << n << endl;
        // cout << "prefix_sum[i]=" << prefix_sum[i] << ", prefix_sum[x]=" << prefix_sum[x] << ", suffix_sum[i]=" << suffix_sum[i] << ", suffix_sum[x]=" << suffix_sum[x] << endl;

        int remain = n <= i + x ? n - i : x;
        // cout << "remain=" << remain << endl;
        // cout << "prefix_sum[n - i - x]=" << prefix_sum[n - i - remain] << endl;
        // cout << "suffix_sum[n - x - i]=" << suffix_sum[n - remain - i] << endl;
        // cout << "suffix_sum[n - i]=" << suffix_sum[n - i] << endl;
        int a1 = prefix_sum[n - i - remain] - suffix_sum[n - remain - i] + suffix_sum[n - i];
        // cout << "a1=" << a1 << endl;
        ans = max(ans, a1);
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
