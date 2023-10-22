#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
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
    int t;
    cin >> t;

    int d = 1000;
    int c = 1;
    int ans = 0;
    rep(i, 4)
    {
        int input = t / d % 10;
        if (input == 0)
        {
            input = 10;
        }
        ans += abs(input - c) + 1;
        c = input;
        d /= 10;
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
