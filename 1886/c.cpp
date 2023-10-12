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
    string S;
    cin >> S;
    int pos;
    cin >> pos;

    int n = S.size();

    sort(S.begin(), S.end());

    // cout << "n=" << n << ", pos=" << pos << endl;
    vector<long long> sum(n + 1);
    sum[0] = n;
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + n - i;
    }

    // cout << "sum: ";
    // for (auto x : sum)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    int idx = 0;
    while (pos > sum[idx])
    {
        pos -= sum[idx];
        idx++;
    }
    // cout << "idx=" << idx << ", pos=" << pos << endl;

    cout << S[pos];
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
    cout << endl;

    return 0;
}
