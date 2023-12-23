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
    int n, k;

    cin >> n >> k;

    vector<ll> a(n);
    vector<ll> b(n);

    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    rep(i, n)
    {
        rep(j, k)
        {
            if (j < i)
            {
                dp[i + 1][j + 1] = dp[i][j + 1];
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i][j - i] + a[i] + b[j - i]);
            }
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
