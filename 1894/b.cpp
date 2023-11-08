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

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    if (n < 3)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> freq(100, 0);
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }

    int multi_num = 0;
    for (int i = 0; i < 100; i++)
    {
        if (freq[i] > 1)
        {
            // cout << "i=" << i + 1 << ", freq[i]=" << freq[i] << endl;
            multi_num++;
        }
    }

    if (multi_num <= 1)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> b(n);

    bool use_2 = false;
    bool use_3 = false;

    for (int i = 0; i < n; i++)
    {
        if (freq[a[i]] >= 2)
        {
            if (!use_2)
            {
                b[i] = 2;
                use_2 = true;
            }
            else if (!use_3)
            {
                b[i] = 3;
                use_3 = true;
            }
            else
            {
                b[i] = 1;
            }
            freq[a[i]] = 1;
        }
        else
        {
            b[i] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
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
