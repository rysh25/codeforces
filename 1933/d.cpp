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
    int mx = 0;
    map<int, int> m;

    set<int> s;

    rep(i, n)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        m[a[i]]++;
        s.emplace(a[i]);
    }

    if (s.size() == 1)
    {
        cout << "NO" << endl;
        return;
    }

    for (auto [k, v] : m)
    {
        if (k < mx && v > 1)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
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
