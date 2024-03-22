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

    vector<string> s(n);

    rep(i, n)
    {
        cin >> s[i];
    }

    int prev = 0;
    rep(i, n)
    {
        int num1 = 0;
        rep(j, n)
        {
            if (s[i][j] == '1')
            {
                num1++;
            }
        }

        if (prev > 0)
        {
            if (prev == num1)
            {
                cout << "SQUARE" << endl;
            }
            else
            {
                cout << "TRIANGLE" << endl;
            }
            return;
        }
        prev = num1;
    }
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
