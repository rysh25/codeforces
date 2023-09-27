#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define endl '\n'

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<set<int>> sets(n);
    set<int> union_all;

    rep(i, n)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int x;
            cin >> x;
            sets[i].insert(x);
            union_all.insert(x);
        }
    }

    // cout << "union_all " << union_all.size() << ": ";
    // for (auto x : union_all)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    int max_size = 0;

    for (auto i : union_all)
    {
        // cout << "i=" << i << endl;
        set<int> s;
        rep(j, n)
        {
            // cout << "j=" << j << endl;
            if (sets[j].count(i) > 0)
            {
                continue;
            }
            s.insert(sets[j].begin(), sets[j].end());
        }

        // cout << "s " << s.size() << ": ";
        // for (auto x : s)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;

        if (union_all.size() != s.size())
        {
            max_size = max(max_size, (int)s.size());
        }
    }

    cout << max_size << endl;
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
