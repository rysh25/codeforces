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
    string a, b, c;
    cin >> n >> a >> b >> c;

    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            if (a[i] != c[i])
            {
                ans = true;
            }
        }
        else
        {
            if (a[i] != c[i] and b[i] != c[i])
            {
                ans = true;
            }
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';
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
