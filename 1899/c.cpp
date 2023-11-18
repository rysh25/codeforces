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
    rep(i, n) cin >> a[i];

    int INF = 1e9 + 7;
    vector<int> dp(n + 1, -INF);
    dp[0] = a[0];

    for (int i = 0; i < n - 1; i++)
    {
        // cout << "a[i]%2=" << a[i] % 2 << ", a[i+1]%2=" << a[i + 1] % 2 << endl;
        if ((a[i] % 2 + 2) % 2 != (a[i + 1] % 2 + 2) % 2)
        {
            dp[i + 1] = max(a[i + 1], dp[i] + a[i + 1]);
        }
        else
        {
            dp[i + 1] = a[i + 1];
        }
    }

    // cout << "dp: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    cout << *max_element(dp.begin(), dp.end()) << endl;
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
