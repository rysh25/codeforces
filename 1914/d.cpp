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

    vector<pair<int, int>> a(n);
    vector<pair<int, int>> b(n);
    vector<pair<int, int>> c(n);

    rep(i, n)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    rep(i, n)
    {
        cin >> b[i].first;
        b[i].second = i;
    }

    rep(i, n)
    {
        cin >> c[i].first;
        c[i].second = i;
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    vector<vector<pair<int, int>>> v(3);
    v[0] = a;
    v[1] = b;
    v[2] = c;

    vector<int> perm = {0, 1, 2};

    int ans = 0;
    do
    {
        int count = 0;
        set<int> used_index;
        for (int p : perm)
        {
            rep(i, n)
            {
                if (used_index.count(v[p][i].second) > 0)
                {
                    continue;
                }
                count += v[p][i].first;
                used_index.insert(v[p][i].second);
                break;
            }
        }
        ans = max(ans, count);

    } while (next_permutation(perm.begin(), perm.end()));

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
