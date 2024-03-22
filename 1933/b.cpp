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

    int sum = 0;
    int r1 = 0;
    int r2 = 0;
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] % 3 == 1)
        {
            r1++;
        }
        else if (a[i] % 3 == 2)
        {
            r2++;
        }
    }

    if (sum % 3 == 0)
    {
        cout << 0 << endl;
    }
    else if (sum % 3 == 1)
    {
        if (r1 > 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    else if (sum % 3 == 2)
    {
        cout << 1 << endl;
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
