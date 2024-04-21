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
    string x, y;
    cin >> x >> y;

    int n = x.size();

    string ans_x = x, ans_y = y;

    bool x_is_greater = false;
    int greater_i = -1;

    for (int i = 0; i < n; i++)
    {
        if (x[i] > y[i])
        {
            x_is_greater = true;
            greater_i = i;
            break;
        }
        else if (x[i] < y[i])
        {
            x_is_greater = false;
            greater_i = i;
            break;
        }
    }

    // cerr << "x_is_greater: " << x_is_greater << " greater_i: " << greater_i << endl; // debug

    for (int i = greater_i + 1; i < n; i++)
    {
        if (x_is_greater)
        {
            ans_x[i] = x[i] >= y[i] ? y[i] : x[i];
            ans_y[i] = x[i] >= y[i] ? x[i] : y[i];
        }
        else
        {
            ans_y[i] = x[i] >= y[i] ? y[i] : x[i];
            ans_x[i] = x[i] >= y[i] ? x[i] : y[i];
        }
    }

    cout << ans_x << endl;
    cout << ans_y << endl;
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
