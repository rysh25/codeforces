#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

#define endl '\n'

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int t1 = min(min(a, b), c);
    int t3 = max(max(a, b), c);
    int t2 = a + b + c - t1 - t3;

    if (a == b && a == c)
    {
        cout << "YES" << endl;
    }
    else if (t1 == t2 && t1 * 2 == t3)
    {
        cout << "YES" << endl;
    }
    else if ((t1 * 2 == t2 && t1 * 2 == t3) ||
             (t1 == t2 && t1 * 3 == t3))
    {
        cout << "YES" << endl;
    }
    else if ((t1 * 2 == t2 && t1 * 3 == t3) ||
             t1 == t2 && t1 * 4 == t3)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
