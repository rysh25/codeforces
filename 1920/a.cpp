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

    int mn = 0;
    int mx = 1e9 + 1;

    vector<int> exclude;

    rep(i, n)
    {
        int a, x;
        cin >> a >> x;

        switch (a)
        {
        case 1:
            mn = max(mn, x);
            break;
        case 2:
            mx = min(mx, x);
            break;
        case 3:
            exclude.push_back(x);
            break;
        }
    }
    // cout << "mn: " << mn << ", mx: " << mx << endl;

    int count = 0;
    for (auto x : exclude)
    {
        if (x >= mn && x <= mx)
        {
            count++;
        }
    }

    // cout << "count: " << count << endl;

    cout << max(mx - mn + 1 - count, 0) << endl;
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
