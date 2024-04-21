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

    vector<vector<int>> G(n, vector<int>());

    rep(i, n - 1)
    {
        int v, u;
        cin >> v >> u;

        v--, u--;

        G[v].push_back(u);
        G[u].push_back(v);
    }

    auto dfs = [&](auto &&f, int v, int p = -1) -> int
    {
        int size = 1;
        for (int u : G[v])
        {
            if (u != p)
            {
                size += f(f, u, v);
            }
        }
        return size;
    };

    auto is_posible = [&](int n, int k, int x) -> bool
    {
        for (int i = 0; i < n; ++i)
        {
            int subtree_size = dfs(dfs, i);
            if (subtree_size < x && n - subtree_size < k)
            {
                return false;
            }
        }
        return true;
    };

    // dfs(dfs, 0);

    // cout << "tree_size: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << tree_size[i] << " ";
    // }
    // cout << endl;

    int left = 1, right = n;
    int ans = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (is_posible(n, k, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
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
