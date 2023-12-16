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

    // cout << "s=" << s << endl;

    int ans = 0;
    while (true)
    {
        deque<pair<int, int>> st; // value, index
        int max_value = 0;
        for (int i = 0; i < n; i++)
        {
            max_value = max(max_value, s[i] - '0');
            while (!st.empty() && st.back().first < s[i] - '0')
                st.pop_back();

            st.emplace_back(s[i] - '0', i);
        }

        // cout << "st: " << st.size() << endl;
        // for (auto [v, i] : st)
        // {
        //     cout << "(" << (char)(v + '0') << ", " << i << "), ";
        // }
        // cout << endl;

        if (max_value == s[s.size() - 1] - '0')
        {
            for (int i = 1; i < n; i++)
            {
                if (s[i - 1] - '0' > s[i] - '0')
                {
                    cout << -1 << endl;
                    return;
                }
            }

            cout << ans << endl;

            return;
        }
        else
        {
            // right shit
            int sz = st.size();

            vector<char> t(s.begin(), s.end());
            int last = t[st[sz - 1].second];
            for (int i = st.size() - 1; i > 0; i--)
            {
                // cout << "(i - 1 + sz) % sz=" << (i - 1 + sz) % sz << endl;
                // cout << "st[(i - 1 + sz) % sz].second=" << st[(i - 1 + sz) % sz].second << endl;
                t[st[i].second] = t[st[i - 1].second];
            }
            t[st[0].second] = last;
            s = string(t.begin(), t.end());
            // cout << "s=" << s << endl;
        }

        ans++;
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
