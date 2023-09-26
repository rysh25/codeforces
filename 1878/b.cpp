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

    vector<int> a(n);

    a[0] = 1;
    a[1] = 5;
    for (int i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + 4;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    // for (int i = 2; i < n; i++)
    // {
    //     if (3 * a[i] % (a[i - 1] + a[i - 2]) == 0)
    //     {
    //         cout << "Error" << endl;
    //         return;
    //     }
    // }
    cout << endl;
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
