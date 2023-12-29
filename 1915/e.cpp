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

    vector<ll> prefix_sum_odd;
    vector<ll> prefix_sum_even;

    prefix_sum_odd.push_back(0);
    prefix_sum_even.push_back(0);

    rep(i, n)
    {
        if (i % 2 == 0)
        {
            prefix_sum_odd.push_back(prefix_sum_odd.back() + a[i]);
        }
        else
        {
            prefix_sum_even.push_back(prefix_sum_even.back() + a[i]);
        }
    }

    cout << "prefix_sum_odd: ";
    for (auto e : prefix_sum_odd)
    {
        cout << e << " ";
    }
    cout << endl;

    cout << "prefix_sum_even: ";
    for (auto e : prefix_sum_even)
    {
        cout << e << " ";
    }
    cout << endl;

    for (int l = 1; l <= (n + 1) / 2; ++l)
    {
        for (int r = l; r <= n / 2; ++r)
        {
            if ((prefix_sum_odd[r] - prefix_sum_odd[l - 1]) == (prefix_sum_even[r] - prefix_sum_even[l - 1]))
            {
                cout << "l: " << l << ", r: " << r << endl;
                cout << prefix_sum_odd[r] - prefix_sum_odd[l - 1] << endl;
                cout << prefix_sum_even[r] - prefix_sum_even[l - 1] << endl;
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
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
