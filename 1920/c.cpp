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

    int mx = 0;
    rep(i, n)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int ans = 1;

    vector<int> remains;

    bool identical = true;
    for (int j = 2; j <= mx; j++)
    {
        // cout << "j=" << j << endl;

        remains.clear();
        for (int k = 0; k < 1; k++)
        {
            remains.push_back(a[k] % j);
        }

        for (int k = 1; k < n; k++)
        {
            if (remains[k % 1] != a[k] % j)
            {
                identical = false;
                break;
            }
        }
    }

    if (identical)
    {
        ans++;
    }

    if (n % 2 == 0)
    {
        for (int i = 2; i * i < n; i++)
        {
            for (int j = 2; j <= mx; j++)
            {
                // cout << "j=" << j << endl;

                remains.clear();
                for (int k = 1; k < i + 1; k++)
                {
                    remains.push_back(a[k] % j);
                }

                // cout << "remains: ";
                // for (auto x : remains)
                // {
                //     cout << x << " ";
                // }
                // cout << endl;

                for (int k = 1; k < n; k++)
                {
                    if (remains[k % 1] != a[k] % j)
                    {
                        identical = false;
                        break;
                    }
                }
            }

            if (identical)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
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
