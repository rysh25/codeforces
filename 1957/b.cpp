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
    int n, k;
    cin >> n >> k;

    if (n == 1)
    {
        cout << k << endl;
        return;
    }

    int x = 1;
    while (true)
    {
        if (x * 2 > k)
        {
            break;
        }

        x *= 2;
    }

    vector<int> ans(n, 0);

    // cerr << "x=" << x << ", k=" << k << ", k-x=" << k - (x - 1) << endl;
    // cerr << "x-1=" << x - 1 << " " << bitset<8>(x - 1) << endl;
    // cerr << "k-x-1=" << k - (x - 1) << " " << bitset<8>(k - (x - 1)) << endl;

    ans[0] = x - 1;
    ans[1] = k - (x - 1);

    rep(i, n)
    {
        cout << ans[i] << " ";
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
