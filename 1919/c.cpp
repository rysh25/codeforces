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
    rep(i, n)
    {
        cin >> a[i];
    }

    int penalty_s = 0;
    int penalty_t = 0;

    int prev_s = 1e9 + 1;
    int prev_t = 1e9 + 1;
    rep(i, n)
    {
        if (a[i] <= prev_s && a[i] <= prev_t)
        {
            if (prev_s <= prev_t)
            {
                prev_s = a[i];
            }
            else
            {
                prev_t = a[i];
            }
        }
        else if (a[i] <= prev_s)
        {
            prev_s = a[i];
        }
        else if (a[i] <= prev_t)
        {
            prev_t = a[i];
        }
        else
        {
            if (prev_s <= prev_t)
            {
                penalty_s++;
                prev_s = a[i];
            }
            else
            {
                penalty_t++;
                prev_t = a[i];
            }
        }
    }

    cout << penalty_s + penalty_t << endl;
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
