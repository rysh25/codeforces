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

    string s;
    cin >> s;

    int a_wins = 0;
    int b_wins = 0;

    for (int i = 1; i <= n; i++)
    {
        int a_sets = 0, a_plays = 0;
        int b_sets = 0, b_plays = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 'A')
            {
                a_plays++;
            }
            else
            {
                b_plays++;
            }

            if (i <= max(a_plays, b_plays))
            {
                if (a_plays > b_plays)
                {
                    // cout << "A" << endl;
                    a_sets++;
                }
                else
                {
                    // cout << "B" << endl;
                    b_sets++;
                }

                a_plays = 0;
                b_plays = 0;
            }
        }

        if (s[s.size() - 1] == 'A' && a_sets == b_sets + 1)
        {
            a_wins++;
        }
        else if (s[s.size() - 1] == 'B' && a_sets + 1 == b_sets)
        {
            b_wins++;
        }

        // cout << "i=" << i << " a_sets=" << a_sets << " b_sets=" << b_sets << " a_wins=" << a_wins << " b_wins=" << b_wins << endl;
    }

    if (a_wins > 0 && b_wins == 0)
    {
        cout << "A" << endl;
    }
    else if (b_wins > 0 && a_wins == 0)
    {
        cout << "B" << endl;
    }
    else
    {
        cout << "?" << endl;
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
