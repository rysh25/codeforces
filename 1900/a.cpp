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
    string s;
    cin >> s;

    int ans = 0;
    int empty_streak = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#')
        {
            if (empty_streak == 2)
            {
                ans++;
            }
            empty_streak = 0;
        }
        else if (s[i] == '.')
        {
            empty_streak++;
            if (empty_streak == 1 || empty_streak == 3)
            {
                ans++;
            }
        }

        if (empty_streak == 3)
        {
            break;
        }
    }

    if (empty_streak == 2)
    {
        ans++;
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
