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

    vector<ll> prefix_sum(n + 1, 0);
    vector<int> prefix_count_odd(n + 1, 0);
    vector<int> prefix_count_even(n + 1, 0);

    rep(i, n)
    {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
        prefix_count_odd[i + 1] = prefix_count_odd[i] + (a[i] % 2);
        prefix_count_even[i + 1] = prefix_count_even[i] + (a[i] % 2 == 0 ? 1 : 0);
    }

    // cout << "prefix_sum: ";
    // for (auto e : prefix_sum)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;
    // cout << "prefix_count_even: ";
    // for (auto e : prefix_count_even)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;
    // cout << "prefix_count_odd:  ";
    // for (auto e : prefix_count_odd)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;

    rep(i, n)
    {
        if (i == 0)
        {
            cout << prefix_sum[i + 1] << " ";
        }
        else
        {
            int r = prefix_count_odd[i + 1] / 3;
            if (prefix_count_odd[i + 1] % 3 == 1)
            {
                r += 1;
            }
            cout << prefix_sum[i + 1] - r << " ";
        }
    }
    cout << endl;
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
