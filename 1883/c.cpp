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

vector<pair<long long, long long>> prime_factorize(long long N)
{
    vector<pair<long long, long long>> res;
    for (long long a = 2; a * a <= N; ++a)
    {
        if (N % a != 0)
            continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0)
        {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1)
        res.push_back({N, 1});
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    const auto &k_primes = prime_factorize(k);

    const ll INF = 1e18 + 1;
    set<int> seen;
    auto minnum = [&](int k) -> tuple<ll, int>
    {
        ll ans = INF;
        int index = -1;
        rep(i, n)
        {
            if (seen.count(i))
            {
                continue;
            }
            // cout << "!!" << a[i] << " " << ((a[i] + (k - 1)) / k) * k - a[i] << endl;
            ll a1 = ((a[i] + (k - 1)) / k) * k - a[i];
            if (a1 < ans)
            {
                ans = a1;
                index = i;
            }
        }
        return {ans, index};
    };

    auto [a1, index1] = minnum(k);

    ll a2 = 0;

    for (int i = k_primes.size() - 1; i >= 0; i--)
    {
        const auto p = k_primes[i];
        for (int j = 0; j < p.second; j++)
        {
            auto [a, index2] = minnum(p.first);
            a2 += a;
            seen.insert(index2);
        }
    }

    ll ans = min(a1, a2);

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
