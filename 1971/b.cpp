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
    string s;
    cin >> s;

    bool same = true;
    int index = -1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[0])
        {
            same = false;
            index = i;
            break;
        }
    }

    if (same)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;

        cout << s[index];

        for (int i = 1; i < s.size(); i++)
        {
            if (i == index)
            {
                cout << s[0];
            }
            else
            {

                cout << s[i];
            }
        }

        cout << endl;
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
