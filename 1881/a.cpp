#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

#define endl '\n'

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    string x, s;
    cin >> x >> s;

    // cout << "x=" << x << ", s=" << s << endl;
    // cout << "x.size()=" << x.size() << ", s.size()=" << s.size() << endl;

    // cout << "i=" << i << endl;

    // cout << "x=" << x << ", x.size()=" << x.size() << ", m=" << m << endl;

    for (int j = 0; j < 55; j++)
    {
        // cout << "j=" << j << ", x.size() + j=" << x.size() + j << ", m=" << m << endl;

        int count = 0;
        int length = n;
        bool is_substring = true;
        int k = 0;
        for (k = 0; k < m; k++)
        {
            if (j + k >= length)
            {
                // cout << "j + k=" << j + k << ", length=" << length << endl;
                count++;
                length *= 2;
            }

            // cout << "x[j+k]=" << x[j + k] << ", s[k]=" << s[k] << endl;
            if (x[(j + k) % n] != s[k])
            {
                is_substring = false;
                break;
            }
        }

        if (is_substring)
        {
            // cout << "k=" << k << ", count=" << count << endl;
            cout << count << endl;
            return;
        }
    }
    cout << -1 << endl;
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
