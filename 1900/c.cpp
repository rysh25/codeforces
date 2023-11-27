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
    string s;
    cin >> s;

    vector<pair<int, int>> graph(n);

    rep(i, n)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        // cout << "i=" << i << ", l=" << l << ", r=" << r << endl;
        graph[i] = pair(l, r);
    }

    queue<pair<int, int>> q;
    q.emplace(0, 0);

    int ans = 1e9 + 1;
    while (!q.empty())
    {
        auto [cur, cost] = q.front();
        q.pop();

        // cout << "cur=" << cur << ", cost=" << cost << endl;
        // cout << "graph[cur].first=" << graph[cur].first << ", graph[cur].second=" << graph[cur].second << endl;

        if (graph[cur].first == -1 &&
            graph[cur].second == -1)
        {
            ans = min(ans, cost);
        }

        if (graph[cur].first != -1)
        {
            if (s[cur] == 'L')
            {
                q.emplace(graph[cur].first, cost);
            }
            else
            {
                q.emplace(graph[cur].first, cost + 1);
            }
        }

        if (graph[cur].second != -1)
        {
            if (s[cur] == 'R')
            {
                q.emplace(graph[cur].second, cost);
            }
            else
            {
                q.emplace(graph[cur].second, cost + 1);
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
