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
    int n, c, d;
    cin >> n >> c >> d;
    map<int, int> mp;

    int mn = 1e9 + 1;
    rep(i, n * n)
    {
        int a;
        cin >> a;
        mp[a]++;
        mn = min(mn, a);
    }

    rep(i, n)
    {
        int x = 0;
        if (i == 0)
        {
            x = mn;
        }
        else
        {
            x = mn + i * d;
        }
        rep(j, n)
        {
            // cout << "x: " << x + j * c << endl;
            if (mp[x + j * c] == 0)
            {
                cout << "NO" << endl;
                return;
            }
            mp[x + j * c]--;
        }
    }

    cout << "YES" << endl;
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
