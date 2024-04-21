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
    int n, m, k;
    cin >> n >> m >> k;

    // cout << "n: " << n << " m: " << m << " k: " << k << endl;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<int> b(m);
    map<int, int> mp;
    rep(i, m)
    {
        cin >> b[i];
        mp[b[i]]++;
    }

    map<int, int> mp2;
    int match = 0;
    int j = 0;
    int ans = 0;
    for (int i = 0; i < n - m; i++)
    {
        while (i + j < n && j - i < m)
        {
            if (mp[a[i + j]] > mp2[a[i + j]])
            {
                mp2[a[i + j]]++;
                match++;
            }
            j++;
        }

        if (match == k)
        {
            ans++;
        }

        mp2[a[i]]--;

        if (mp[a[i]] > 0)
        {
            match--;
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
