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
    string s;
    cin >> s;

    stack<char> st1, st2, st3, st4;

    for (int i = 0; i < n; i++)
    {
        char c1 = s[i];
        char c2 = s[n - i - 1];
        if (!st1.empty() && st1.top() != c1)
        {
            st1.pop();
        }
        else
        {
            st1.push(c1);
        }

        if (!st2.empty() && st2.top() != c2)
        {
            st2.pop();
        }
        else
        {
            st2.push(c2);
        }
    }

    bool prev_is_same1 = false;
    bool prev_is_same2 = false;

    for (int i = 0; i < n; i++)
    {
        char c1 = s[i];
        char c2 = s[n - i - 1];

        if (!st3.empty() && st3.top() == c1)
        {
            prev_is_same1 = true;
        }
        else
        {
            prev_is_same1 = false;
        }

        if (!st4.empty() && st4.top() == c2)
        {
            prev_is_same2 = true;
        }
        else
        {
            prev_is_same2 = false;
        }

        if (!prev_is_same1 && !st3.empty() && st3.top() != c1)
        {
            st3.pop();
        }
        else
        {
            st3.push(c1);
        }

        if (!prev_is_same2 && !st4.empty() && st4.top() != c2)
        {
            st4.pop();
        }
        else
        {
            st4.push(c2);
        }
    }

    int ans = min(min(st1.size(), st2.size()), min(st3.size(), st4.size()));

    // cout << "s=" << s << endl;
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
