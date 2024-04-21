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
    int k, q;
    cin >> k >> q;

    vector<int> a(k);

    rep(i, k)
    {
        cin >> a[i];
    }
    rep(i, q)
    {
        int n;
        cin >> n;

        if (n >= a[0])
        {
            // cerr << "n > a[0]" << endl; // debug
            cout << a[0] - 1 << " ";
        }
        else
        {
            // cerr << "n <= a[0]" << endl; // debug
            cout << n << " ";
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
