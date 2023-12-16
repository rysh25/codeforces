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
    vector<vector<int>> G(n, vector<int>());
    // cout << "n=" << n << endl;
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        // cout << "i=" << i << ", u=" << u << ", v=" << v << endl;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int ans = 0;

    if (G[0].size() == 1)
    {
        ans++;
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        visited[cur] = true;

        bool is_leaf = true;
        // cout << "cur=" << cur << endl;
        for (auto next : G[cur])
        {
            if (visited[next])
                continue;
            is_leaf = false;
            q.push(next);
        }
        if (is_leaf)
        {
            // cout << "leaf: cur=" << cur << endl;
            ans++;
        }
    }

    if (ans == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << (ans + 1) / 2 << endl;
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
