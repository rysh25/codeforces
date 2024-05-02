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

    vector<int> x(n);

    rep(i, n - 1) cin >> x[i + 1];

    vector<int> a(n);

    a[0] = x[1] + 1;

    for (int i = 1; i < n; i++)
    {
        a[i] = x[i];

        if (a[i - 1] == 0)
        {
            a[i] += a[i - 1];
        }

        while (i < n - 1 && a[i] <= x[i + 1])
        {
            a[i] += a[i - 1];
        }
    }

    rep(i, n) cout << a[i] << " ";
    cout << endl;

    // cerr << "a: ";
    // for (int i = 1; i < n; i++)
    // {
    //     cerr << a[i] % a[i - 1] << " ";
    // }
    // cerr << endl;
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
