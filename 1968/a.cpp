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
    int x;
    cin >> x;

    // cerr << "x: " << x << endl;

    int y = x - 1;
    int mx = y + 1;
    // cerr << "y: " << y << " mx: " << mx << endl;

    for (int i = x / 2; 0 < i; i--)
    {
        if (x % i == 0)
        {
            if (mx < i + i)
            {
                // cerr << "i: " << i << " i+i: " << i + i << endl;
                y = i;
                mx = i + i;
            }
        }
    }

    // cerr << "mx: " << mx << " y: " << y << endl;
    cout << y << endl;
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
