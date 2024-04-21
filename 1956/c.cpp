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

    int s = 0;

    // int m = n + h;
    // for (int i = 1; i <= n; i++)
    // {
    //     s += i * h;

    //     if (i > h)
    //     {
    //         s += i * n;
    //     }
    // }

    int h = n / 2;

    // cerr << "n=" << n << ", h=" << h << ", h/2=" << h / 2 << endl; // debug

    int m = n + h + (h / 2);
    for (int i = 1; i <= n; i++)
    {
        if (i <= h / 2)
        {
            s += i * (h / 2);
        }
        else if (i <= h)
        {
            s += i * (h + (h / 2));
        }
        else
        {
            s += i * h;
            s += i * n;
        }
    }

    // cout << "s=" << s << ", m=" << m << endl; // debug
    cout << s << " " << m << endl;

    rep(i, m)
    {
        if (i < n)
        {
            cout << 1 << " " << i + 1 << " ";
            rep(j, n)
            {
                cout << j + 1 << " ";
            }
        }
        else if (i < n + h)
        {
            cout << 2 << " " << i - n + 1 << " ";
            rep(j, n)
            {
                cout << j + 1 << " ";
            }
        }
        else
        {
            cout << 1 << " " << i - n - h + 1 << " ";
            rep(j, n)
            {
                cout << j + 1 << " ";
            }
        }

        cout << endl;
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
