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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    rep(i, n)
    {
        cin >> a[i];
    }
    bool found = false;
    for (int i = 0; i < n && !found; ++i)
    {
        int k_count = 0;
        int others_count = 0;
        for (int j = i; j < n && !found; ++j)
        {
            if (a[j] == k)
            {
                ++k_count;
            }
            else
            {
                ++others_count;
            }
            if (k_count > others_count)
            {
                found = true;
            }
        }
    }

    cout << (found ? "YES" : "NO") << endl;
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
