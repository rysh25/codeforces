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
    rep(i, n) cin >> a[i];

    vector<int> bit_count(20, 0);

    set<int> bits;

    rep(i, n)
    {
        int x = a[i];
        int bit = 0;
        while (x > 0)
        {
            if ((x & 1) == 1)
            {
                bits.insert(bit);
            }

            x >>= 1;
            bit++;
        }
    }

    // cerr << "bits.size() = " << bits.size() << endl;
    // rep(i, 21)
    // {
    //     cerr << "i: " << i << " bits.count(i): " << bits.count(i) << endl;
    // }

    auto is_ok = [&](vector<int> &bit_count) -> bool
    {
        for (int b : bits)
        {
            if (bit_count[b] == 0)
            {
                return false;
            }
        }

        return true;
    };

    auto inc_bits = [&](int x, vector<int> &bit_count) -> void
    {
        int bit = 0;
        while (x > 0)
        {
            if ((x & 1) == 1)
            {
                bit_count[bit]++;
            }

            x >>= 1;
            bit++;
        }
    };

    auto dec_bits = [&](int x, vector<int> &bit_count) -> void
    {
        int bit = 0;
        while (x > 0)
        {
            if ((x & 1) == 1)
            {
                bit_count[bit]--;
            }

            x >>= 1;
            bit++;
        }
    };

    int l = 0, r = 0;

    int ans = 0;

    inc_bits(a[r], bit_count);
    while (r < n && !is_ok(bit_count))
    {
        r++;
        inc_bits(a[r], bit_count);
    }
    ans = max(ans, r - l + 1);
    // cerr << "l=" << l << " r=" << r << " r-l+1=" << r - l + 1 << endl;

    while (r < n)
    {
        // cerr << "1: l=" << l << " r=" << r << endl;
        while (l < r)
        {
            vector<int> tmp = bit_count;
            dec_bits(a[l], tmp);
            if (!is_ok(tmp))
            {
                break;
            }
            dec_bits(a[l], bit_count);
            l++;
        }

        ans = max(ans, r - l + 1);
        // cerr << "l=" << l << " r=" << r << " r-l+1=" << r - l + 1 << endl;

        r++;

        if (r < n)
        {
            inc_bits(a[r], bit_count);
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
