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

    vector<pair<char, int>> upper_st;
    vector<pair<char, int>> lower_st;

    rep(i, s.size())
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (s[i] == 'B')
            {
                if (!upper_st.empty())
                {
                    upper_st.pop_back();
                }
            }
            else
            {
                upper_st.emplace_back(make_pair(s[i], i));
            }
        }
        else
        {
            if (s[i] == 'b')
            {
                if (!lower_st.empty())
                {
                    lower_st.pop_back();
                }
            }
            else
            {
                lower_st.emplace_back(make_pair(s[i], i));
            }
        }
    }

    int i = 0, j = 0;

    while (i < upper_st.size() || j < lower_st.size())
    {
        if (i < upper_st.size() && j < lower_st.size())
        {
            if (upper_st[i].second < lower_st[j].second)
            {
                cout << upper_st[i].first;
                i++;
            }
            else
            {
                cout << lower_st[j].first;
                j++;
            }
        }
        else if (i < upper_st.size())
        {
            cout << upper_st[i].first;
            i++;
        }
        else
        {
            cout << lower_st[j].first;
            j++;
        }
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
