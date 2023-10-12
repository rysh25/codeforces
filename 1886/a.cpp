#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define endl '\n'

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    for (int x = 1; x <= n; x++)
    {
        if (x % 3 == 0)
            continue;

        for (int y = x + 1; y <= n; y++)
        {
            if (y % 3 == 0)
                continue;

            int z = n - x - y;

            if (y < z && z <= n && z % 3 != 0)
            {
                cout << "YES" << endl;
                cout << x << " " << y << " " << z << endl;
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
