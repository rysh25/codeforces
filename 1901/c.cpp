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
    int x = 1e9 + 7, y = -1e9 + 7;
    rep(i, n)
    {
        cin >> a[i];
        x = min(x, a[i]);
        y = max(y, a[i]);
    }

    int op = 0;
    vector<int> ans;
    while (x != y)
    {
        int z = y - x;

        x = (x + z) / 2;
        y = (y + z) / 2;
        op++;
        if (op <= n)
            ans.emplace_back(z);
    }
    cout << op << endl;
    if (0 < op && op <= n)
    {
        for (int i = 0; i < op; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
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
