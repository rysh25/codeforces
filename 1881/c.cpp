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
    int n;
    cin >> n;

    vector<string> matrix(n);

    rep(i, n)
    {
        cin >> matrix[i];
    }

    int count = 0;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {

            vector<int> v(4);
            v[0] = matrix[i][j] - 'a';
            v[1] = matrix[n - j - 1][i] - 'a';
            v[2] = matrix[n - i - 1][n - j - 1] - 'a';
            v[3] = matrix[j][n - i - 1] - 'a';
            int mx = max(max(v[0], v[1]), max(v[2], v[3]));
            for (int k = 0; k < 4; k++)
            {
                count += mx - v[k];
            }
        }
    }

    cout << count << endl;
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
