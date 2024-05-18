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
    int ans = 0;

    char head = s[0];

    int count_01 = 0;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] > s[i])
        {
            ans++;

            if (head != s[i - 1])
            {
                count_01++;
            }
            head = s[i];
        }
    }

    if (head != s[s.size() - 1])
    {
        count_01++;
    }

    if (count_01 > 1)
    {
        ans += count_01 - 1;
    }

    // cerr << "ans: " << ans << " count_01: " << count_01 << endl;

    cout << ans + 1 << endl;
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
