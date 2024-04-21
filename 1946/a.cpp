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

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    sort(a.begin(), a.end());

    int mid = (n - 1) / 2;

    int median = a[mid];

    int count_median = 0;
    int count_smaller = 0;

    rep(i, n)
    {
        if (a[i] == median)
        {
            count_median++;
        }
        else if (a[i] < median)
        {
            count_smaller++;
        }
    }

    // cout << "mid=" << mid << " median=" << median << " count_median=" << count_median << " count_smaller=" << count_smaller << endl;

    if (count_median + count_smaller <= (mid + 1))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << count_median + count_smaller - mid << endl;
    }
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
